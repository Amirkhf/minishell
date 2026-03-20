/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:14:04 by amary             #+#    #+#             */
/*   Updated: 2026/03/20 00:49:40 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <sys/wait.h>

void	exec_simple_cmd(t_data *data, t_cmd *cmd)
{
	pid_t	pid;
	char	*cmd_path;

	cmd_path = get_cmd_path(data, cmd->args[0]);
	if (!cmd_path)
	{
		write(2, "minishell: command not found\n", 29);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		handle_redirections(cmd);
		execve(cmd_path, cmd->args, data->env);
		perror("execve");
		exit(127);
	}
	waitpid(pid, NULL, 0);
	return ;
}

void	my_exec(t_data *data)
{
	if (!data->cmds || !data->cmds->args || !data->cmds->args[0])
		my_exit(data->garbage_tmp, data->garbage_perm, EXIT_FAILURE);
	else if (!data->cmds->next && is_builtin(data->cmds->args[0]))
	{
		exec_builtin(data, data->cmds);
		return ;
	}
	exec_simple_cmd(data, data->cmds);
}
