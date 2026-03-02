/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:03:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 12:41:16 by amkhelif         ###   ########.fr       */
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

void	add_token(t_garbage **head_gc, t_token *head_token, t_lexer_type *type,
		char *value)
{
	t_token *tmp;
	t_token *new_token;

	tmp = head_token;
	if (!(tmp))
		return (NULL);

	while (tmp != NULL)
	{
		tmp = tmp->next;
	}
	new_token = lst_new_token(head_gc, type, value);
	tmp->next = new_token;
}