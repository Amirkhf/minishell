/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:03:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 12:03:32 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// create a new node and add it to the garbage list
void	gc_add(t_garbage **head, void *data, int type)
{
	t_garbage	*new;

	new = ft_lstnew(data, type); // create a new node
	new->next = *head;           // the next is head
	*head = new;                 // head is new node
}

void	add_token(t_token **head, t_garbage **lst_free, char *value, t_token_type *type)
{
	t_token *new_token;

	new_token = lst_new_token(lst_free, value, type);
	new_token->next = *head;
	*head = new_token;
}