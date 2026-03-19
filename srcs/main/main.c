/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:27:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/19 19:18:45 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	loop(t_data *data)
{
	t_token	*token;

	while (1)
	{
		if (!(my_readline(data)))
			continue ;
		token = token_line(data);
		if (token == NULL)
		{
			free_all(&data->garbage_tmp);
			continue ;
		}
		if (parsing(data, &token))
		{
			free_all(&data->garbage_tmp);
			continue ;
		}
		build_cmds(data);
		my_exec(data);
		free_all(&data->garbage_tmp);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	argc = 0;
	argv = NULL;
	i = 0;
	if (init_struct(&data, env))
		return (EXIT_FAILURE);
	loop(&data);
	return (EXIT_SUCCESS);
}
