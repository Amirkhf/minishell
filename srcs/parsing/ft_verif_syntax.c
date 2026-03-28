/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:51:20 by amary             #+#    #+#             */
/*   Updated: 2026/03/28 17:55:58 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_verif_syntax(t_token *tmp)
{
	if (tmp->type == PIPE) 
	{
    	if (tmp->next == NULL || tmp->next->type == PIPE)
    		return (syntax_error("newline"), EXIT_FAILURE);
	}
	else if (tmp->type > PIPE && tmp->type <= APPEND)
	{
    	if (tmp->next == NULL || (tmp->next->type >= PIPE && tmp->next->type <= APPEND))
    		return (syntax_error("newline"), EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
