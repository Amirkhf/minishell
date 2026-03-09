/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 15:03:45 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void loop(t_data *data, char **env)
{
	t_token *token;

	while (1)
	{
		if (!(my_readline(data, env)))
			continue;
		token = token_line(data);
		if (token == NULL)
		{
			free_all(&data->garbage_tmp);
			continue;
		}
		if (parsing(data, &token))
		{
			free_all(&data->garbage_tmp);
			continue;
		}
		print_token(data);
		free_all(&data->garbage_tmp);
	}
}

int main(int argc, char **argv, char **env)
{
	t_data data;
	int i;

	i = 0;
	if (init_struct(&data, env))
		return (EXIT_FAILURE);
	loop(&data, env);
	return (EXIT_SUCCESS);
}
