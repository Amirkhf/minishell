/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_many_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:29:36 by amary             #+#    #+#             */
/*   Updated: 2026/03/28 17:36:02 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	to_many_arg(t_data *data, t_cmd *cmd)
{
	if (cmd->args[2])
	{
		write(2, "minishell: cd: too many arguments\n", 35);
		data->exit_status = 1;
		return (1);
	}
	return (0);
}
