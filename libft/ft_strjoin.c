/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:40:35 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 17:41:30 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int i;
    int j;

    j = 0;
    i = 0;
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    while (s1[j])
    {
        str[i] = s1[j];
        i++;
        j++;
    }
    j = 0;
    while (s2[j])
    {
        str[i] = s2[j];
        j++;
        i++;
    }
    str[i] = '\0';
    return (str);
}
