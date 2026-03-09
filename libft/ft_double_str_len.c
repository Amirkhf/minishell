/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_str_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:32:41 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 12:34:43 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

long long	ft_double_str_len(char **str)
{
	int i;
	int j;
	int len;

	len = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	return (len + 1);
}
