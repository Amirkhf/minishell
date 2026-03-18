/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:24:26 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/16 14:18:02 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_lexer(t_token **token);
int	parsing(t_data *data, t_token **token)
{
	printf("je suis dans le parsing\n");
	if (check_lexer(token) || expander(data))
		return (EXIT_FAILURE);
	return (0);
}

int	check_lexer(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	if (!(tmp))
		return (EXIT_FAILURE);
	
	if (tmp->type == PIPE)
		return (syntax_error("|"), EXIT_FAILURE);
		
	while (tmp)
	{
		if (tmp->type >= PIPE && tmp->type <= APPEND)
		{
			if (tmp->next == NULL)
				return (syntax_error("newline"), EXIT_FAILURE);
			if (tmp->next->type >= PIPE && tmp->next->type <= APPEND)
				return (syntax_error(tmp->next->str), EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}