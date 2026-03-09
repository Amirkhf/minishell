/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:46:59 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/06 16:47:54 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Alloue de la mémoire et l'ajoute au GC
void	*my_malloc(t_data *data, size_t size, bool type)
{
	void	*memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	if (type == TMP)
		gc_add(&data->garbage_tmp, memory);
	else
		gc_add(&data->garbage_perm, memory);
	return (memory);
}

// Ajoute un bloc mémoire au GC
void	gc_add(t_garbage **lst, void *data)
{
	t_garbage *node;

	node = ft_lstnew_gc(data);
	if (!node)
	{
		free(data);
		perror("minishell: malloc failed");
		exit(1); // remlplace par free_all plus tard
	}
	node->next = *lst;
	*lst = node;
}