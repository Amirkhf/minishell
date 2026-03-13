/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:14:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/13 14:59:06 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_quote(char *str);
// Lit une ligne de commande
// verifie si tout les quote ouverte sont fermer
int	my_readline(t_data *data)
{
	data->line = readline("Minishell : ");
	if (!(data->line))
		return (0);
	gc_add(&data->garbage_tmp, data->line);
	if (count_quote(data->line) == true)
	{
		add_history(data->line);
		return (msg_error_quote(), free_all(&data->garbage_tmp), 0);
	}
	add_history(data->line);
	return (1);
}

static int	count_quote(char *str)
{
	int		i;
	bool	simple_quote;
	bool	double_quote;

	i = 0;
	double_quote = 0;
	simple_quote = 0;
	while (str[i])
	{
		if (double_quote || simple_quote)
		{
			if (str[i] == DOUBLE_QUOTE_C && simple_quote == false)
				double_quote = 0;
			else if (str[i] == SIMPLE_QUOTE_C && double_quote == false)
				simple_quote = 0;
		}
		else
		{
			if (str[i] == SIMPLE_QUOTE_C && double_quote == false)
				simple_quote = 1;
			else if (str[i] == DOUBLE_QUOTE_C && simple_quote == false)
				double_quote = 1;
		}
		i++;
	}
	if (double_quote == true || simple_quote == true)
		return (1);
	return (0);
}
