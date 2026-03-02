/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 12:18:51 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"







void	token_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == '|')
			// ajouter ca dans la liste chaine
		else if (line[i] == '<')
			// ajouter ca dans la liste chaine
		else if (line[i] == '>')
			// ajouter ca dans la liste chaine
		else
			// c une commande
		i++;
	}
}

void	loop(t_data *data)
{
	while (1)
	{
		data->line = readline("test : ");
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
	loop(data.lst_free, &data);
	return (free_all(data.lst_free), EXIT_SUCCESS);
}
