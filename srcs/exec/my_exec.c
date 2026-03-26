/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:14:04 by amary             #+#    #+#             */
/*   Updated: 2026/03/26 20:02:35 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	setup_child_pipes(t_cmd *cmd, int *fd, int prev_pipe)
{
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (cmd->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	return ;
}

void	handle_parent(t_cmd *cmd, int *fd, int *prev_pipe)
{
	if (*prev_pipe != -1)
		close(*prev_pipe);
	if (cmd->next)
	{
		close(fd[1]);
		*prev_pipe = fd[0];
	}
}

void	run_cmd(t_data *data, t_cmd *cmd)
{
	char	*path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (is_builtin(cmd->args[0]))
	{
		exec_builtin(data, cmd);
		my_exit(data->garbage_tmp, data->garbage_perm,data->exit_status);
	}
	path = get_cmd_path(data, cmd->args[0]);
	if (!path)
	{
		write(2, "minishell: command not found\n", 29);
		my_exit(&data->garbage_tmp, &data->garbage_perm, 127);
	}
	execve(path, cmd->args, data->env);
	perror(cmd->args[0]);
	if (errno == EACCES || errno == EISDIR)
		exit(126);
	exit(127);
}

void	exec_pipeline(t_data *data, t_cmd *cmd)
{
	int		fd[2];
	int		prev_pipe;
	pid_t	pid;

	prev_pipe = -1;
	while (cmd)
	{
		if (cmd->next)
			pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			setup_child_pipes(cmd, fd, prev_pipe);
			if (handle_redirections(cmd) == 1)
				my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
			if (!cmd->args || !cmd->args[0])
				my_exit(&data->garbage_tmp, &data->garbage_perm, 0);
			run_cmd(data, cmd);
		}
		handle_parent(cmd, fd, &prev_pipe);
		cmd = cmd->next;
	}
	wait_pipeline(data, pid);
}

void	my_exec(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmds;
	if (!cmd)
		return ;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (!cmd->next && cmd->args && cmd->args[0] && is_builtin(cmd->args[0]))
		exec_single_builtin(data, cmd);
	else
		exec_pipeline(data, cmd);
	setup_signals();
}
