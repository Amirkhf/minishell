/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 15:02:49 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*take_cmd(char *line, int *i);

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
		else if (is_sign(line[i]))
			add_token(&data->lst_free, &token, token_type(line[i]), &line[i]);
		else
			add_token(&data->lst_free, &token, CMD, take_cmd(line, i));
		i++;
	}
}

static char	*take_cmd(char *line, int i)
{
	char *cmd;
	int j;

	j = 0;
	cmd = malloc((ft_strlen(line) + 1) * sizeof(char));
	if (!(cmd))
		return (NULL);
	while (line && line[i])
	{
		cmd[j] = line[i];
		j++;
		(i)++;
	}
	return (cmd);
}