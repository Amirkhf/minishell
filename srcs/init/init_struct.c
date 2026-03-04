/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:31:50 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 15:08:49 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Initialise la structure de données
void	init_struct(t_data *data, char **env)
{
	data->env = env;
	data->garbage_perm = NULL;
	data->garbage_tmp = NULL;
	data->line = NULL;
	data->token = NULL;
}