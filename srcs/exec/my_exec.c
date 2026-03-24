/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:14:04 by amary             #+#    #+#             */
/*   Updated: 2026/03/24 12:15:30 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <sys/wait.h>

// Gère les dup2 pour l'enfant
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

// Gère les close pour le parent et met à jour prev_pipe
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

// Exécute la commande (Built-in ou execve) et quitte l'enfant
void	run_cmd(t_data *data, t_cmd *cmd)
{
	char	*path;

	if (is_builtin(cmd->args[0]))
	{
		exec_builtin(data, cmd);
		exit(0);
	}
	path = get_cmd_path(data, cmd->args[0]);
	if (!path)
	{
		write(2, "minishell: command not found\n", 29);
		exit(127);
	}
	execve(path, cmd->args, data->env);
	perror("execve");
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
			handle_redirections(cmd);
			run_cmd(data, cmd);
		}
		handle_parent(cmd, fd, &prev_pipe);
		cmd = cmd->next;
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void	my_exec(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmds;
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (!cmd->next && is_builtin(cmd->args[0]))
	{
		exec_builtin(data, cmd);
		return ;
	}
	exec_pipeline(data, cmd);
}
