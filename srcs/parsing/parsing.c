/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:24:26 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:29:04 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_lexer(t_token **token);
static t_token	*remove_tok(t_data *data, t_token *tok);
static void	remove_empty_tokens(t_data *data);

int	parsing(t_data *data, t_token **token)
{
	if (check_lexer(token) || expander(data))
		return (EXIT_FAILURE);
	remove_quote(data);
	remove_empty_tokens(data);
	return (0);
}

static t_token	*remove_tok(t_data *data, t_token *tok)
{
	t_token	*next;

	next = tok->next;
	if (tok->prev)
		tok->prev->next = next;
	else
		data->token = next;
	if (next)
		next->prev = tok->prev;
	return (next);
}

static void	remove_empty_tokens(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if ((tmp->type == CMD || tmp->type == ARGV)
			&& tmp->str && tmp->str[0] == '\0')
		{
			tmp = remove_tok(data, tmp);
			continue ;
		}
		tmp = tmp->next;
	}
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
		if (tmp->type == PIPE)
		{
			if (tmp->next == NULL)
				return (syntax_error("newline"), EXIT_FAILURE);
			if (tmp->next->type == PIPE)
				return (syntax_error(tmp->next->str), EXIT_FAILURE);
		}
		else if (tmp->type >= REDIR_IN && tmp->type <= APPEND)
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
