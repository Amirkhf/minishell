/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 14:33:04 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	token_line(t_data *data, char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	while (line[i])
	{
		if (verif_quote(line))
		{
			write(2, "ERROR quote\n", 13);
			break ;
		}
		if (space_or_tab(line[i]))
			i++;
		else if (is_sign(line[i]) >= 0)
			add_token(&data->lst_free, &token, is_sign(line[i]), line[i]);
		i++;
	}
}
// loop main
void	loop(t_data *data)
{
	while (1)
	{
		data->line = readline("test : ");
		if (!(data->line))
			break ;
		gc_add(&data->lst_free, data->line, STRING); // add gc_collector
		token_line(data, data->line);
		add_history(data->line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	init_struct(&data, env);
	loop(&data);
	return (free_all(data.lst_free), EXIT_SUCCESS);
}
