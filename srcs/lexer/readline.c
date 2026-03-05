/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:14:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/05 17:32:18 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Lit une ligne de commande
int	my_readline(t_data *data)
{
	data->line = readline("test : ");
	if (!(data->line))
		return (0);
	gc_add(&data->garbage_tmp, data->line);
	if (count_quote(data->line) == true)
		return (msg_error_quote(), free_all(&data->garbage_tmp), 0);
	return (1);
}

int	count_quote(char *str)
{
	int i;
	bool in_quote;
	bool double_quote;

	double_quote = 0;
	in_quote = 0;
	i = 0;
	while (str[i])
	{
		if (in_quote || double_quote)
		{
			if (str[i] == SIMPLE_QUOTE_c && double_quote == false)
				in_quote = 0;
			else if (str[i] == DOUBLE_QUOTE_c && in_quote == false)
				double_quote = 0;
		}
		else
		{
			if (str[i] == SIMPLE_QUOTE_c && double_quote == false)
				in_quote = 1;
			else if (str[i] == DOUBLE_QUOTE_c && in_quote == false)
				double_quote = 1;
		}
		i++;
	}
	if (double_quote == true || in_quote == true)
		return 1;
	return 0;
}

	// ajoute a la liste de token si c un >> ou <<
	void take_big_operator(t_data * data, int operator, int * i)
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
	void take_small_operator(t_data * data, int operator, int * i)
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