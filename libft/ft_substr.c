/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:26:43 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 16:27:00 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	true_len(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start])
	{
		i++;
		start++;
	}
	if (len >= i)
		return (i);
	else if (start > ft_strlen(s))
		return (0);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	len_s;

	if (!s || (len < 0))
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	len = true_len(s, start, len);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if ((start >= len_s) || (start < 0))
		return (str[0] = '\0', str);
	while (i < len && s[start])
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
