/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:50:23 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/24 15:40:19 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
char	*swap_function(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[j])
	{
		str[j] = '-';
		j++;
	}
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	return (str);
}
char	*ft_itoa(t_data *data, int n)
{
	char *str;
	int i;

	i = 0;
	str = my_malloc(data, count_digit(n) + 1, TMP);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	swap_function(str);
	return (str);
}