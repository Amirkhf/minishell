/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:24:26 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 11:23:05 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing(t_data *data, t_token **token)
{
	if (check_lexer(data, token) || expander(data, &data->token))
		return (1);
	return (0);
}

int	expander(t_data *data, t_token **token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp->next)
	{
		if (is_double_quote(tmp->str))
		{
			extract_variable(tmp->str);
		}
		tmp = tmp->next;
	}
}

// checks for syntax errors
int	check_lexer(t_data *data, t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	if (!(tmp))
		return (1);
	if (tmp->type == PIPE)
		return (syntax_error("|"), 1);
	while (tmp->next != NULL)
	{
		if (tmp->prev && is_operator(tmp->str) && is_operator(tmp->str))
			return (syntax_error(tmp->str), 1);
		tmp = tmp->next;
	}
	if (tmp->prev && is_operator(tmp->str) && is_operator(tmp->str))
		return (syntax_error(tmp->str), 1);
	else if (tmp->type > 1)
		return (syntax_error("newline"), 1);
	return (0);
}
