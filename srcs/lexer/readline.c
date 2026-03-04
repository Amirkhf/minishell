/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:14:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 16:22:23 by amkhelif         ###   ########.fr       */
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
	return (1);
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