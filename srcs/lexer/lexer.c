/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 12:03:14 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer_funtion(t_garbage **lst_free, t_token *token, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == SPACE || line[i] == TAB)
			i++;
		if (line[i] == PIPE)
			add_token(&token,lst_free,PIPE);
		i++;
	}
	return (0);
}