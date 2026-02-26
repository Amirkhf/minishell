/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:33:51 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 12:58:43 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_garbage	*ft_lstlast(t_garbage *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}

// int main (void)
// {
// 	t_list **new_list;

// 	new_list = malloc(sizeof(t_list) * 3);
// 	new_list[0] = ft_lstnew("amir");
// 	new_list[1] = ft_lstnew("amine");
// 	new_list[2] = ft_lstnew("walid");

// 	new_list[0]->next = new_list[1];
// 	new_list[1]->next = new_list[2];

// 	//printf("%d",ft_lstsize(new_list));
// 	printf("%s",ft_lstlast(new_list)->content);
// }
