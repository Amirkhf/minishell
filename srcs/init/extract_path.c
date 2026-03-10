/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:28:39 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 14:21:13 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fill_my_env(t_data *data, char **env);
// extract the path from the env variable
char	**extract_env(t_data *data, char **env)
{
	int	len;

	len = ft_double_str_len(env);
	data->env = my_malloc(data, (len + 1) * sizeof(char *), PERM);
	if (!(data->env))
		return (NULL);
	fill_my_env(data, env);
	if (!(data->env) || data->env[0][0] == '\0')
		return (NULL);
	return (data->env);
}

// recupere la variable env est la copie
static void	fill_my_env(t_data *data, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		data->env[i] = my_malloc(data, ft_strlen(env[i]) + 1, PERM);
		if (!(data->env[i]))
			my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
		while (env[i][j])
		{
			data->env[i][j] = env[i][j];
			j++;
		}
		data->env[i][j] = '\0';
		i++;
	}
	data->env[i] = NULL;
}
