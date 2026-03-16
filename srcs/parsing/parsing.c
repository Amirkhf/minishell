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

// checks for syntax errors
static int	check_lexer(t_token **token)
{
	t_token	*tmp;

	printf("je suis dans la fonction check_lexer\n");
	tmp = *token;
	if (!(tmp))
		return (EXIT_FAILURE);
	if (tmp->type == PIPE)
		return (syntax_error("|"), EXIT_FAILURE);
	while (tmp->next != NULL)
	{
		if (tmp->prev && is_operator(tmp->str) && is_operator(tmp->str))
			return (syntax_error(tmp->str), EXIT_FAILURE);
		tmp = tmp->next;
	}
	if (tmp->prev && is_operator(tmp->str) && is_operator(tmp->str))
		return (syntax_error(tmp->str), EXIT_FAILURE);
	else if (tmp->type > 1)
		return (syntax_error("newline"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
