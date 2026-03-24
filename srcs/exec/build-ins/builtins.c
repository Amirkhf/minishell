/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:33:01 by amary             #+#    #+#             */
/*   Updated: 2026/03/24 12:10:24 by amary            ###   ########.fr       */
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

void	ft_cd(t_data *data, t_cmd *cmd)
{
	if (!cmd->args[1])
		return ;
	if (chdir(cmd->args[1]) != 0)
		perror("minishell: cd");
	return ;
}

void	ft_exit(t_data *data)
{
	int	exit_code;

	exit_code = 0;
	printf("exit\n");
	free_all(&data->garbage_tmp);
	free_all(&data->garbage_perm);
	exit(exit_code);
}

void	exec_builtin(t_data *data, t_cmd *cmd)
{
	char	*name;

	name = cmd->args[0];
	if (ft_strncmp(name, "cd", 3) == 0)
		ft_cd(data, cmd);
	else if (ft_strncmp(name, "exit", 5) == 0)
		ft_exit(data);
	else if (ft_strncmp(name, "pwd", 4) == 0)
		ft_pwd();
	// else if (ft_strncmp(name, "echo", 5) == 0)
	// 	ft_echo();
}
