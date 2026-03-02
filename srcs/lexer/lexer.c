/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 18:05:04 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*token_line(t_data *data, t_token *token, char *line)
{
	int		i;
	char	*cmd;

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
		else if (is_sign(line[i]))
			add_token(&data->lst_free, &token, token_type(line[i]), &line[i]);
		else
		{
			cmd = take_cmd(data, line, i);
			if (!(cmd))
				return (NULL);
			add_token(&data->lst_free, &token, CMD, cmd);
		}
		i++;
	}
	return ("OK"); // changer ca plus tard
}

char	*take_cmd(t_data *data, char *line, int i)
{
	char *cmd;
	int j;

	j = 0;
	cmd = my_malloc(&data->lst_free, (ft_strlen(line) + 1) * sizeof(char));
	if (!(cmd))
		return (NULL);
	while (line && line[i])
	{
		cmd[j] = line[i];
		j++;
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}