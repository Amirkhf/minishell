/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:24:26 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/05 11:41:58 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing(t_data *data, t_token **token)
{
	if (check_lexer(data, token))
		return (1);
	return (0);
}

// checks for syntax errors
int	check_lexer(t_data *data, t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	if (!(tmp))
		return (1);
	if (tmp->type == PIPE)
		return (syntax_error("|"), 1);
	while (tmp->next != NULL)
	{
		if (tmp->prev && tmp->type > 1 && tmp->prev->type > 1)
			return (syntax_error(tmp->str), 1);
		tmp = tmp->next;
	}
	if (tmp->prev && tmp->type > 1 && tmp->prev->type > 1)
		return (syntax_error(tmp->str), 1);
	else if (tmp->type > 1)
		return (syntax_error("newline"), 1);
	return (0);
}

// char	**list_to_tab_checked(t_data *data, t_token **token, int size)
// {
// 	t_token	*tmp;
// 	char	**str;
// 	int		i;

// 	i = 0;
// 	str = my_malloc(data, size, TMP);
// 	if (!(str))
// 		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
// 	tmp = *token;
// 	while (tmp)
// 	{
// 		str[i] = ft_strdup(data, tmp->str);
// 		if (!(str[i]))
// 			my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
// 		tmp = tmp->next;
// 	}
// 	return (str);
// }

// le dernier token pipe
// le premier aussi
//  ou ||