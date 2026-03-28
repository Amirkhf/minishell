/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:00:55 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/28 17:37:36 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* cd.c                                               :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: amkhelif <amkhelif@learner.42.tech>        +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/03/26 12:00:55 by amkhelif          #+#    #+#             */
/* Updated: 2026/03/26 12:00:57 by amkhelif         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_cd(t_data *data, t_cmd *cmd)
{
	char	*path;

	if (!cmd->args[1])
	{
		path = get_env_path(data->env, "HOME");
		if (!path)
		{
			write(2, "minishell: cd: HOME not set\n", 28);
			data->exit_status = 1;
			return ;
		}
	}
	else
		path = cmd->args[1];
	if (to_many_arg(data, cmd) == 1)
		return ;
	if (chdir(path) != 0)
	{
		perror("minishell: cd");
		data->exit_status = 1;
	}
	else
		data->exit_status = 0;
}
