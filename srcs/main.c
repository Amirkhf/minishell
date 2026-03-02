/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 11:23:29 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	loop(t_garbage *lst_free, t_data *data)
{
	t_token	token;

	while (1)
	{
		data->line = readline("test : ");
		// implement the lexer here
		if (lexer_funtion(lst_free,&token, data->line))
			return ; // check if we need to free here
		gc_add(&data->lst_free, data->line, STRING);
		add_history(data->line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	init_struct(&data, env);
	loop(data.lst_free,&data);
	return (free_all(data.lst_free), EXIT_SUCCESS);
}
