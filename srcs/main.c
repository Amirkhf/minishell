/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 10:35:31 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// loop main
void	loop(t_data *data)
{
	t_token	*token;

	while (1)
	{
		data->line = readline("test : ");
		if (!(data->line))
			break ;
		gc_add(&data->garbage_tmp, data->line);
		token = token_line(data);
		add_history(data->line);
		free_all(&data->garbage_tmp);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	init_struct(&data, env);
	loop(&data);
	return (EXIT_SUCCESS);
}
