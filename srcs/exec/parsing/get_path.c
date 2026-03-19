/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:54:20 by amary             #+#    #+#             */
/*   Updated: 2026/03/19 19:25:59 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	has_slash(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '/')
			return (true);
		i++;
	}
	return (false);
}

char	*get_env_path(char **envp, char *key)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(key);
	while (envp[j])
	{
		if (ft_strncmp(envp[j], key, len) == 0 && envp[j][len] == '=')
			return (envp[j] + len + 1);
		j++;
	}
	return (NULL);
}

char	*check(char *cmd_name, char **env)
{
	if (cmd_name == NULL || cmd_name[0] == '\0' || env[0] == NULL)
		return (NULL);
	if (has_slash(cmd_name))
	{
		if (access(cmd_name, X_OK) == 0)
			return (cmd_name);
		else
			return (NULL);
	}
	return (NULL);
}

char	*get_cmd_path(t_data *data, char *cmd_name)
{
	int		j;
	char	*env_path;
	char	*cmd_path;
	char	**paths;
	char	*tmp;

	tmp = check(cmd_name, data->env);
	if (tmp)
		return (tmp);
	env_path = get_env_path(data->env, "PATH");
	if (!env_path)
		return (NULL);
	paths = ft_split(data, env_path, ':');
	if (!paths)
		return (NULL);
	j = 0;
	while (paths[j])
	{
		tmp = ft_strjoin(data, paths[j], "/");
		cmd_path = ft_strjoin(data, tmp, cmd_name);
		if (cmd_path && access(cmd_path, X_OK) == 0)
			return (cmd_path);
		j++;
	}
	return (NULL);
}
