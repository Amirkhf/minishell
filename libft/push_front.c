/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:03:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 16:15:49 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// create a new noeud and add in a new list (garbege)
void	gc_add(t_garbage **head, void *data, int type)
{
	t_garbage	*new;

	new = ft_lstnew(data, type); // create a new noeud
	new->next = *head;           // the next is head
	*head = new;                 // head is new noeud
}
