/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 16:20:43 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*token_line(t_data *data)
{
	int	i;
	int	operator;

	i = 0;
	data->token = NULL;
	while (data->line[i])
	{
		if (is_space(data->line[i]))
			i++;
		else if ((operator= what_operator(data->line, &i)) <= 6)
		{
			if (operator>= 5 && operator<= 6)
				take_big_operator(data, operator, & i);
			else if (operator!= 0 && operator!= 1)
				take_small_operator(data, operator, & i);
		}
		else
		{
			if (!(take_cmd(data, &data->token, data->line, &i)))
				my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		}
	}
	return (data->token);
}
// ajoute a la liste de token si c un >> ou <<
void	take_big_operator(t_data *data, int operator, int * i)
{
	if (operator== HEREDOC)
	{
		if (!(add_token(data, &data->token, HEREDOC, "<<")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		(*i) += 2;
	}
	else
	{
		if (!(add_token(data, &data->token, APPEND, ">>")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		(*i) += 2;
	}
}

// ajoute a la liste de token si c | < >
void	take_small_operator(t_data *data, int operator, int * i)
{
	if (operator== 2)
	{
		if (!(add_token(data, &data->token, PIPE, "|")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		(*i)++;
	}
	else if (operator== 3)
	{
		if (!(add_token(data, &data->token, REDIR_IN, "<")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		(*i)++;
	}
	else if (operator== 4)
	{
		if (!(add_token(data, &data->token, REDIR_OUT, ">")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		(*i)++;
	}
}

// Ajoute un token à la liste
bool	add_token(t_data *data, t_token **token_lst, t_token_type type,
		char *value)
{
	t_token *new;
	t_token *tmp;

	new = new_token(data, value, type);
	if (!(new))
	{
		perror("");
		return (0);
	}
	if (*token_lst == NULL)
	{
		(*token_lst) = new;
		new->prev = NULL;
		return (1);
	}
	tmp = *token_lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	return (1);
}