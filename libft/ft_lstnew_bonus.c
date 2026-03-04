/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:11:04 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 14:49:13 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Crée un noeud pour le GC
t_garbage	*ft_lstnew_gc(void *value)
{
	t_garbage	*new_node;

	new_node = malloc(sizeof(t_garbage));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

// Crée un nouveau token
t_token	*new_token(t_data *data, char *str, t_token_type type)
{
	t_token	*new;

	new = my_malloc(data,sizeof(t_token),TMP);
	if (!(new))
		return (NULL);
	new->type = type;
	new->str = str;
	new->next = NULL;
	return (new);
}

// adds a new token to the back of the token list
void	token_add_back(t_data *data, t_token **head, t_token *new)
{
	t_token *tmp;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}