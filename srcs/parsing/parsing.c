/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:24:26 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 12:43:33 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int parsing(t_data *data, t_token **token)
{
	printf("je suis dans le parsing\n");
	if (check_lexer(data, token) || expander(data, &data->token))
		return (EXIT_FAILURE);
	return (0);
}



// fonction principal qui va cree la valeur a partie de ca $
char *extract_variable(t_data *data, char *str)
{
	bool no_exist;
	char *new_value;

	new_value = NULL;
	no_exist = 0;
	char *name;
	long long len_expanded;
	name = extract_var_name(data, str);
	if (!(name))
		my_exit(data->garbage_tmp, data->garbage_perm, EXIT_FAILURE);
	len_expanded = expanded_len(data, str, name);
	if (len_expanded < 0)
		no_exist = 1;
	new_value = fill_expanded_str(data, str, len_expanded, name);
	if (!(new_value))
		return (NULL);
	return (new_value);
}

// checks for syntax errors
int check_lexer(t_data *data, t_token **token)
{
	t_token *tmp;

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
