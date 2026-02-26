/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:32:33 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 12:58:55 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_garbage	*ft_lstlast(t_garbage *lst);

void	ft_lstadd_back(t_garbage **lst, t_garbage *new)
{
	if (!lst || !new) // if the lst is empty
		return ;
	if (!*lst) // if is a first new
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
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
// 	//printf("%s",ft_lstlast(new_list)->content);
// 	ft_lstadd_back(new_list,ft_lstnew("ok"));
// 	printf("%s",ft_lstlast(new_list)->content);
// }
