/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:23:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 17:52:29 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_double_quote(char *str)
{
	int	i;

	printf("je suis dans la fonction is_double_quote\n");
	i = 0;
	if (str[i] == '"')
	{
		while (str[++i])
		{
			if (str[i] == '"')
				return (1);
		}
	}
	return (0);
}

int	is_simple_quote(char *str)
{
	int	i;

	printf("je suis dans la fonction simple quote\n");
	i = 0;
	if (str[i] == '\'')
	{
		while (str[++i])
		{
			if (str[i] == '\'')
				return (1);
		}
	}
	return (0);
}

int	is_variable_env(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}
