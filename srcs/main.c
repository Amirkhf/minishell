/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:14:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/24 17:39:34 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	main(int argc, char **argv, char **env)
{
	t_data data;

	// recuper la variable denvironnement (env)
	take_path_exec(&data,env);
	if (!(data.my_path))
		return (EXIT_FAILURE);
}