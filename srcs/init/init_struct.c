/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:31:50 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 16:10:27 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Initialise la structure de données
int init_struct(t_data *data, char **env)
{
	data->env = extract_env(data, env);
	if (!(data->env))
		return (EXIT_FAILURE);
	data->garbage_perm = NULL;
	data->garbage_tmp = NULL;
	data->line = NULL;
	data->token = NULL;
	return (EXIT_SUCCESS);
}
