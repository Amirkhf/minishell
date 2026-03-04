/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:14:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 14:31:03 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Lit une ligne de commande
int	my_readline(t_data *data)
{
	data->line = readline("test : ");
	if (!(data->line))
		return (0);
	gc_add(&data->garbage_tmp, data->line);
	return (1);
}