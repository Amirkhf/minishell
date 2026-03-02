/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:45:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 14:34:45 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// check double quote
bool	verif_quote(char *line)
{
	int	i;
	int	open;

	open = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '"')
			open++;
		i++;
	}
	if (open % 2 != 0)
		return (1);
	return (0);
}
// check if is it a space or tabulation
bool	space_or_tab(char c)
{
	int	i;

	i = 0;
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

// is '|' or '<' or '>'
bool	is_sign(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}
