/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:48:05 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/23 14:35:42 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_digit(int n)
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

static char	*swap_function(char *str)
{
	int		i;
	int		j;
	char	tmp;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[j] == '-')
	{
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

char	*ft_itoa(t_data *data,int n)
{
	char	*str;
	int		i;
	long	nb;

	i = 0;
	nb = n;
	str = my_malloc(data,count_digit(nb) + 1,TMP);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		return (str[0] = '0', str[1] = '\0', str);
	if (nb < 0)
	{
		str[i] = '-';
		nb *= -1;
		i++;
	}
	while (nb != 0)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	str[i] = '\0';
	swap_function(str);
	return (str);
}
// int	main(void)
// {
// 	int		n;
// 	char	*str;

// 	n = 42;
// 	str = ft_itoa(n);
// 	printf("%s", str);
// }
