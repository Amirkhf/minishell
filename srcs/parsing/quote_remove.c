/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:24:38 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/23 12:48:24 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_quote(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

static char	*remove_quote_v2(t_data *data, char *str)
{
	int		i;
	int		j;
	char	in_quote;
	char	*new_str;

	new_str = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (!new_str)
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	i = 0;
	j = 0;
	in_quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && in_quote == 0)
			in_quote = str[i];
		else if (str[i] == in_quote)
			in_quote = 0;
		else
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

// Parcours les tokens pour retirer les quotes
void	remove_quote(t_data *data)
{
	t_token *tmp;

	tmp = data->token;
	while (tmp)
	{
		if (is_quote(tmp->str))
			tmp->str = remove_quote_v2(data, tmp->str);
		tmp = tmp->next;
	}
}