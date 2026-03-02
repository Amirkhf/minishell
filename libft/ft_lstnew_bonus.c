/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:11:04 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 11:43:35 by amkhelif         ###   ########.fr       */
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

// funtciotn create a new node for lst t_token
t_token	*lst_new_token(t_garbage **free_lst, char *value, char *type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!(new))
		return (NULL);
	new->value = value;
	new->type = type;
	new->next = NULL;
	gc_add(free_lst, new, STRING);
		// voir par la suite si on garde ? (elle est peut etre mal placer)
}
