/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:47:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/24 17:25:31 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}
// int	main(void)
// {
// 	char		*str;
// 	const char	*str_1 = "abcdefgh";

// 	str = "abcdwxyz";
// 	printf("%d\n", ft_strncmp(str, str_1, 4));
// 	printf("%d\n", strncmp(str, str_1, 4));
// }
