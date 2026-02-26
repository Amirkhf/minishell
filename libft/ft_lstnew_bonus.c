/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:11:04 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 15:59:25 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_garbage	*ft_lstnew(void *content, int type)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (new == NULL)
		return (NULL);
	if (type) // si c un double tableau
		new->is_2d_array = DBL_STRING;
	else // sinon
		new->is_2d_array = STRING;
	new->data = content;
	new->next = NULL;
	return (new);
}

// int	main(void)
// {
// 	t_list *head = ft_lstnew("1");
// 	head->next = ft_lstnew("2");

// }

// int	main(void)
// {
// 	t_list *noeud;
// 	t_list *noeud_1;

// 	noeud = ft_lstnew("amir");
// 	ft_lstnew("amine");
// 	ft_lstnew("walid");
// 	printf("%s",noeud->content);
// 	return (0);
// }
