/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/06 15:06:56 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	what_operator(char *str, int *i);
static void	take_big_operator(t_data *data, int operator, int * i);
static void	take_small_operator(t_data *data, int operator, int * i);

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
		else if ((what_operator(data->line, &i)) <= 6)
		{
			operator= what_operator(data->line, &i);
			if (operator>= HEREDOC && operator<= APPEND)
				take_big_operator(data, operator, & i);
			else if (operator!= 0 && operator!= 1)
				take_small_operator(data, operator, & i);
		}
		else
		{
			if (!(take_cmd(data, &i)))
				return (data->token = NULL, data->token);
		}
	}
	return (data->token);
}

// Identifie et ajoute un opérateur (modifier cette fonction plus tard)
static int	what_operator(char *str, int *i)
{
	if (!(ft_strncmp(str + *i, HEREDOC_C, 2)))
		return (HEREDOC);
	else if (!(ft_strncmp(str + *i, APPEND_C, 2)))
		return (APPEND);
	else if (!(ft_strncmp(str + *i, REDIR_OUT_C, 1)))
		return (REDIR_OUT);
	else if (!(ft_strncmp(str + *i, REDIR_IN_C, 1)))
		return (REDIR_IN);
	else if (!(ft_strncmp(str + *i, PIPE_C, 1)))
		return (PIPE);
	return (7);
}

// ajoute a la liste de token si c un >> ou <<
static void	take_big_operator(t_data *data, int operator, int * i)
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
static void	take_small_operator(t_data *data, int operator, int * i)
{
	if (operator== 2)
	{
		if (!(add_token(data, &data->token, PIPE, "|")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
		(*i)++;
	}
	else if (operator== 3)
	{
		if (!(add_token(data, &data->token, REDIR_IN, "<")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
		(*i)++;
	}
	else if (operator== 4)
	{
		if (!(add_token(data, &data->token, REDIR_OUT, ">")))
			my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
		(*i)++;
	}
}

//  Verifie si un caractère est un espace ou tabulation
 bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
