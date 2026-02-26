/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:09:49 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 09:19:57 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// ajouter le tableau (ou autre) dans tab free
void	add_tab_free(t_data *data, char *str, char **double_str)
{
	if (str)
	{
		data->tab_free[data->nb_free] = str;
		data->nb_free++;
	}
	else if (double_str)
	{
		data->tab_free[data->nb_free] = double_str;
		data->nb_free++;
	}
}
