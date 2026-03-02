/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:42 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 17:56:17 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*my_malloc(t_garbage **head_gc, int len)
{
	void *memory;
	memory = malloc(len);
	if (memory == NULL)
		return (NULL);
	gc_add(head_gc, memory, 0);
	return (memory);
}