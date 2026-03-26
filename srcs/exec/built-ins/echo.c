/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:15:52 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/24 17:42:38 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


static bool check_option_n(char *line);



void my_echo(t_data *data, t_cmd *cmd)
{
int		i;
	bool	print_newline;

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

static bool check_option_n(char *line)
{
    int i;

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
