/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/05 17:04:04 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Lit et tokenize les commandes
void	loop(t_data *data)
{
	t_token	*token;

	while (1)
	{
		if (!(my_readline(data)))
			continue ;
		add_history(data->line);
		token = token_line(data);
		if (token == NULL)
		{
			free_all(&data->garbage_tmp);
			continue ;
		}
		print_token(data);
		if (parsing(data, &token))
		{
			free_all(&data->garbage_tmp);
			continue ;
		}
		free_all(&data->garbage_tmp);
	}
}

// Point d'entrée du programme
int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	init_struct(&data, env);
	loop(&data);
	return (EXIT_SUCCESS);
}
