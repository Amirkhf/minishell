/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:37:20 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/24 17:24:19 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static int	count_word(char const *str, char c)
{
	int	i;
	int	count;
	int	sign;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && sign)
		{
			count++;
			sign = 0;
		}
		if (str[i] == c)
			sign = 1;
		i++;
	}
	return (count);
}

static int	ft_len(int j, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[j] && s[j] != c)
	{
		i++;
		j++;
	}
	return (i);
}

void	free_function(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*remplissage(char c, int j, char const *s)
{
	int		a;
	char	*str;

	a = 0;
	str = malloc((ft_len(j, s, c) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[j] != c && s[j])
	{
		str[a] = s[j];
		a++;
		j++;
	}
	str[a] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (s == NULL)
		return (NULL);
	str = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++i < count_word(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		str[i] = remplissage(c, j, s);
		if (!str[i])
			return (free_function(str), NULL);
		while (s[j] && s[j] != c)
			j++;
	}
	if (s[0] == '\0')
		str[0] = NULL;
	str[i] = (NULL);
	return (str);
}
// int	main(void)
// {
// 	char	**tab;
// 	int		i;

// 	tab = ft_split("\0aa\0bbb", '\0');
// 	if (!tab)
// 		return (1);
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }
