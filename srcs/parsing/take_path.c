/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:20:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/24 17:39:47 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

// fonction qui recupere est split la variable
// denvironnemet env
void	take_path_exec(t_data *data, char **env)
{
	// implementer le reste demain
}

// fonction qui recherche lindice de la ligne
// ou ce situe tout les chemin
static int	search_line_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}