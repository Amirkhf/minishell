/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanded_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:33:58 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 16:58:55 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// calcule la taille du contenue dune variable denvironnement
long long expanded_len(t_data *data, char *str, char *name_variable)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (data->env[i])
    {
        if (ft_strncmp(data->env[i], name_variable, ft_strlen(name_variable)) == 0)
        {
            while ((data->env[i] + ft_strlen(name_variable) + 1)[j])
                j++;
        }
        i++;
    }
    if (j == 0)
        return (-1);
    return (j + 1);
}