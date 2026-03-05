/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/05 13:53:33 by amkhelif         ###   ########.fr       */
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
				return (data->token = NULL, data->token);
		}
	}
	return (data->token);
}
