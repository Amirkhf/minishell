/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:39:16 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 12:39:38 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// initialise la struct est recupere
// la variable denvironnement env
void	init_struct_data(t_data *data, char **env)
{
	data->env = env;
}
