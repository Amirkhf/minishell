/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:44:41 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 09:49:23 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_env(char **envp, char *search);

// renvoie le tout les chemin dans un **char a partir
// de la variable env
void	extract_path(t_data *data, char **env)
{
	char	*path;

	path = get_env(env, "PATH=");
	if (!(path))
		return ;
	data->env = ft_split(path, ':');
	if (!(data->env))
		return ;
	add_tab_free(data, NULL, data->env);
}

// cherche et renvoie la ligne qui contient
// le path
static char	*get_env(char **envp, char *search)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(search);
	while (envp[j])
	{
		if (ft_strncmp(envp[j], search, len) == 0)
			return (envp[j] + len);
		j++;
	}
	return (NULL);
}
