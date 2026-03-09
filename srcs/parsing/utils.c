/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:23:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 11:49:37 by amkhelif         ###   ########.fr       */
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

char	*extract_variable(t_data *data, char *str)
{
	int		i;
	int		j;
	char	*new_str;

	printf("je suis dans la fonction extract_variable\n");
	j = 0;
	i = 0;
	new_str = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (new_str == NULL)
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	while (str[i])
	{
		if (!(str[i] == '"'))
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	printf("%s\n", new_str);
	return (new_str);
}
