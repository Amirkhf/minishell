/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:26:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 12:52:11 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// return 1 ok
// return 0 pas ok

t_token	*token_line(t_data *data)
{
	int		i;
	t_token	**head;

	i = 0;
	while (data->line[i])
	{
		if (is_space(data->line[i]))
			i++;
		else if (is_operator(data->line[i]))
		{
			if (!(what_operator(data, head, data->line, &i)))
				my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		}
		else
		{
			if (!(take_cmd(data, head, data->line, &i)))
				my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
		}
	}
	return (*head);
}


