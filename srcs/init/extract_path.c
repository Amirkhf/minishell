/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:28:39 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 16:22:05 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// extract the path from the env variable
char **extract_env(t_data *data, char **env)
{
	int len;

	len = ft_double_str_len(env);
	data->env = my_malloc(data, (len + 1) * sizeof(char *), PERM);
	if (!(data->env))
		return (NULL);
	// revenir apres ici 
}

// void copy_env(char *new_env, char **env)
// {
// 	int i;
// 	int j;
// 	int a;

// 	a = 0;
// 	j = 0;
// 	i = 0;
// 	printf("je suis dans la fonction copy_env\n");
// 	while (env[i])
// 	{
// 		j = 0;
// 		while (env[i][j])
// 		{
// 			new_env[a] = env[i][j];
// 			j++;
// 			a++;
// 		}
// 		new_env[a] = '\n';
// 		i++;
// 	}
// 	new_env[a] = '\0';
// 	// printf("%s\n", new_env);
// 	// return (new_env);e
// }
