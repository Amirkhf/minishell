/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:48:09 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:28:21 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Libère toute la mémoire d'une liste GC
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

// Libère la mémoire et quitte le programme
void	my_exit(t_garbage **gc_tmp, t_garbage **gc_perm, int exit_status)
{
	free_all(gc_tmp);
	free_all(gc_perm);
	exit(exit_status);
}
