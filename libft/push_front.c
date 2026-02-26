/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:03:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 13:23:09 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// create a new noeud and add in a new list (garbege)
void	ft_push_front_garbage(t_garbage **head, void *data, int type)
{
	t_garbage *new;

	new = ft_lstnew(data, type); // create a new noeud
	new->next = *head; // the next is head
	*head = new; // head is new noeud
}