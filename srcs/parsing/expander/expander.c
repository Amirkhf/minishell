/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:43:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 12:43:40 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// plus tard
int expander(t_data *data, t_token **token)
{
	t_token *tmp;

	printf("je suis dans la fonction expander\n");
	tmp = *token;
	while (tmp)
	{
		if (is_double_quote(tmp->str) && !(is_variable_env(tmp->str)))
		{
			tmp->str = extract_quote(data, tmp->str);
			if (!(tmp->str))
				return (EXIT_FAILURE);
			tmp->str = extract_variable(data, tmp->str);
			if (!(tmp->str))
				return (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

