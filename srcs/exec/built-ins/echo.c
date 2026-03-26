/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:14:50 by amary             #+#    #+#             */
/*   Updated: 2026/03/26 21:14:51 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static bool	check_option_n(char *line)
{
	int	i;

	if (!line || line[0] != '-' || line[1] == '\0')
		return (false);
	i = 1;
	while (line[i])
	{
		if (line[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	my_echo(t_data *data, t_cmd *cmd)
{
	int		i;
	bool	print_newline;

	(void)data;
	i = 1;
	print_newline = true;
	while (cmd->args[i] && check_option_n(cmd->args[i]))
	{
		print_newline = false;
		i++;
	}
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (print_newline)
		printf("\n");
}
