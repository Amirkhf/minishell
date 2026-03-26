/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:14:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:52:23 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	count_quote(char *str);

int	my_readline(t_data *data)
{
	data->line = readline("Minishell : ");
	if (!(data->line))
	{
		printf("exit\n");
		my_exit(&data->garbage_tmp, &data->garbage_perm, data->exit_status);
	}
	gc_add(&data->garbage_tmp, data->line);
	if (count_quote(data->line) == true)
	{
		add_history(data->line);
		return (msg_error_quote(), free_all(&data->garbage_tmp), 0);
	}
	add_history(data->line);
	return (1);
}

void	init_variable(int *i, bool *double_quote, bool *simple_quote)
{
	*i = 0;
	*double_quote = 0;
	*simple_quote = 0;
}

static int	count_quote(char *str)
{
	int		i;
	bool	simple_quote;
	bool	double_quote;

	init_variable(&i, &simple_quote, &double_quote);
	while (str[i++])
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
	}
	if (double_quote == true || simple_quote == true)
		return (1);
	return (0);
}
