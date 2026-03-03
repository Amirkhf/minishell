/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/03 18:02:29 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// return 1 ok
// return 0 pas ok

t_token	*token_line(t_data *data)
{
	int		i;
	t_token	*new;

	i = 0;
	while (data->line[i])
	{
		if (is_space(data->line[i]))
			i++;
		else if (is_operator(data->line[i]))
		{
			if (!(add_token()))
			{
				return (NULL);
			}
		}
		i++;
	}
}

bool	is_operator(char c)
{
	if (c == "|" || c == "<" || c == ">" || c == "<<" || c == ">>")
		return (1);
	return (0);
}

bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

bool	add_token(t_data *data, t_token **token_lst, t_token_type type,
		char *value)
{
	t_token	*new;
	t_token	*tmp;

	new = new_token(data, value, type);
	if (!(new))
		return (0);
	if (*token_lst == NULL)
	{
		(*token_lst) = new;
		new->prev = NULL;
		return (1);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	return (1);
}
