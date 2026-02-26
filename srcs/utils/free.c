/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:18:20 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 16:16:42 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// free tout ce quon a malloc
void	free_all(t_garbage *lst)
{
	t_garbage	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		if (lst->data)
		{
			if (lst->is_2d_array == DBL_STRING)
				free_function(lst->data);
			else
				free(lst->data);
		}
		free(lst);
		lst = tmp;
	}
}
