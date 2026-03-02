/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:11:04 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 12:38:21 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// function create a new node for lst t_garbage
t_garbage	*ft_lstnew(void *value, int type)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (!(new))
		return (NULL);
	if (type) // if it is a double array
		new->is_2d_array = DBL_STRING;
	else // otherwise
		new->is_2d_array = STRING;
	new->data = value;
	new->next = NULL;
	return (new);
}

// cree le nouveau jeton
t_token	*lst_new_token(t_garbage **head, t_lexer_type *type, char *value)
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if (!(new_token))
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}