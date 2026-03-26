/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:00:55 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 12:00:57 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_cd(t_data *data, t_cmd *cmd)
{
	if (!cmd->args[1])
		return ;
	if (chdir(cmd->args[1]) != 0)
		perror("minishell: cd");
	return ;
}
