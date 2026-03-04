/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:18:20 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 11:48:00 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all(t_garbage **gc)
{
	t_garbage	*tmp;
	t_garbage	*lst;

	if (!gc || !*gc)
		return ;
	lst = *gc;
	while (lst)
	{
		tmp = lst->next;
		if (lst->data)
			free(lst->data);
		free(lst);
		lst = tmp;
	}
	*gc = NULL;
}

// for a exit programme 
void	my_exit(t_garbage **gc_tmp, t_garbage **gc_perm, int exit_status)
{
	free_all(gc_tmp);
	free_all(gc_perm);
	exit(exit_status);
}