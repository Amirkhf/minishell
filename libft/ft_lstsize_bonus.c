/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:01:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 16:40:26 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// fonction qui calcule la taille dune liste chaine
int	ft_lstsize_lexer(t_token *lst)
{
	int		i;
	t_token	*noeud;

	noeud = lst;
	i = 0;
	while (noeud != NULL)
	{
		noeud = noeud->next;
		i++;
	}
	return (i);
}

