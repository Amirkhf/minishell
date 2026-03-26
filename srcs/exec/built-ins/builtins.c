/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:33:01 by amary             #+#    #+#             */
/*   Updated: 2026/03/26 20:36:56 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	is_builtin(char *cmd_name)
{
	if (!cmd_name)
		return (false);
	if (ft_strncmp(cmd_name, "echo", 5) == 0)
		return (true);
	if (ft_strncmp(cmd_name, "cd", 3) == 0)
		return (true);
	if (ft_strncmp(cmd_name, "pwd", 4) == 0)
		return (true);
	if (ft_strncmp(cmd_name, "export", 7) == 0)
		return (true);
	if (ft_strncmp(cmd_name, "unset", 6) == 0)
		return (true);
	if (ft_strncmp(cmd_name, "env", 4) == 0)
		return (true);
	if (ft_strncmp(cmd_name, "exit", 5) == 0)
		return (true);
	return (false);
}

void	exec_builtin(t_data *data, t_cmd *cmd)
{
	char	*name;

	name = cmd->args[0];
	if (ft_strncmp(name, "cd", 3) == 0)
		ft_cd(data, cmd);
	else if (ft_strncmp(name, "exit", 5) == 0)
		ft_exit(data, cmd);
	else if (ft_strncmp(name, "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(name, "echo", 5) == 0) 
		my_echo(data, cmd);
	else if (ft_strncmp(name, "unset", 6) == 0)
		ft_unset(data, cmd);
	else if (ft_strncmp(name, "env", 4) == 0)
		ft_env(data->env);
	else if (ft_strncmp(name, "export", 7) == 0)
		ft_export(data, cmd);
}
