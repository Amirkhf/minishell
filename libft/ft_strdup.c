/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:34:36 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 17:54:27 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup(t_data *data, const char *s)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen(s) + 1;
	str = my_malloc(data, i * sizeof(char), TMP);
	if (str == NULL)
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	while (s[j])
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*int main (void)
{
	char str[100] = "";
	printf("%s\n",ft_strdup(str));
	printf("%s",strdup(str));
}*/
