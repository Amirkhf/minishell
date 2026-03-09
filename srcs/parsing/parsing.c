/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:24:26 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/09 11:45:47 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing(t_data *data, t_token **token)
{
	printf("je suis dans le parsing\n");
	if (check_lexer(data, token) || expander(data, &data->token))
		return (EXIT_FAILURE);
	return (0);
}

int	expander(t_data *data, t_token **token)
{
	t_token	*tmp;

	printf("je suis dans la fonction expander\n");
	tmp = *token;
	while (tmp)
	{
		if (is_double_quote(tmp->str))
		{
			tmp->str = extract_variable(data, tmp->str);
			if (!(tmp->str))
				return (EXIT_FAILURE);
			// printf("%s", tmp->str);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

// checks for syntax errors
int	check_lexer(t_data *data, t_token **token)
{
	t_token	*tmp;

	printf("je suis dans la fonction check_lexer\n");
	tmp = *token;
	if (!(tmp))
		return (EXIT_FAILURE);
	if (tmp->type == PIPE)
		return (syntax_error("|"), EXIT_FAILURE);
	while (tmp->next != NULL)
	{
		if (tmp->prev && is_operator(tmp->str) && is_operator(tmp->str))
			return (syntax_error(tmp->str), EXIT_FAILURE);
		tmp = tmp->next;
	}
	if (tmp->prev && is_operator(tmp->str) && is_operator(tmp->str))
		return (syntax_error(tmp->str), EXIT_FAILURE);
	else if (tmp->type > 1)
		return (syntax_error("newline"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
