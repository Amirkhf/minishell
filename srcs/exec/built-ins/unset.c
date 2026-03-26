/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:02:52 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:16:07 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_valid_name(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0' || (str[0] >= '0' && str[0] <= '9'))
		return (0);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	remove_env_var(t_data *data, int index)
{
	while (data->env[index])
	{
		data->env[index] = data->env[index + 1];
		index++;
	}
}

void	ft_unset(t_data *data, t_cmd *cmd)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (cmd->args[i])
	{
		if (!is_valid_name(cmd->args[i]))
			break ;
		else
		{
			j = 0;
			len = ft_strlen(cmd->args[i]);
			while (data->env[j++])
			{
				if (ft_strncmp(data->env[j], cmd->args[i], len) == 0
					&& (data->env[j][len] == '=' || data->env[j][len] == '\0'))
				{
					remove_env_var(data, j);
					break ;
				}
			}
		}
		i++;
	}
}
