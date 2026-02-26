/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:31:50 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 15:36:26 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// this function its for init a struct data
void	init_struct(t_data *data, char **env)
{
	data->env = env;
	data->lst_free = NULL;
	data->line = NULL;
}