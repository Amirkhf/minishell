/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:55:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 20:16:22 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_export(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->env[i])
	{
		write(1, "declare -x ", 11);
		j = 0;
		while (data->env[i][j] && data->env[i][j] != '=')
			write(1, &data->env[i][j++], 1);
		if (data->env[i][j] == '=')
		{
			write(1, "=\"", 2);
			j++;
			while (data->env[i][j])
				write(1, &data->env[i][j++], 1);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || (str[0] >= '0' && str[0] <= '9') || str[0] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && !(str[i] >= '0' && str[i] <= '9')
			&& str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	add_to_env(t_data *data, char *arg)
{
	int		i;
	int		len;
	char	**new_env;

	i = 0;
	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], arg, len) == 0 && (data->env[i][len] == '='
					|| data->env[i][len] == '\0'))
		{
			data->env[i] = ft_strdup(data, arg);
			return ;
		}
		i++;
	}
	new_env = my_malloc(data, sizeof(char *) * (i + 2), TMP);
	i = -1;
	while (data->env[++i])
		new_env[i] = data->env[i];
	new_env[i] = ft_strdup(data, arg);
	new_env[i + 1] = NULL;
	data->env = new_env;
}

void	ft_export(t_data *data, t_cmd *cmd)
{
	int	i;

	data->exit_status = 0;
	if (!cmd->args[1])
	{
		print_export(data);
		return ;
	}
	i = 1;
	while (cmd->args[i])
	{
		if (!is_valid_identifier(cmd->args[i]))
		{
			write(2, "minishell: export: not a valid identifier\n", 42);
			data->exit_status = 1;
		}
		else
			add_to_env(data, cmd->args[i]);
		i++;
	}
}
