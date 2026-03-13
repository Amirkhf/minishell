/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:47:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/13 14:35:14 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// extrait le nom de la variable
char	*extract_var_name(t_data *data, int *i)
{
	int		j;
	char	*name_variable;

	j = 0;
	name_variable = my_malloc(data, ft_strlen(data->line) + 1, TMP);
	if (!(name_variable))
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	(*i)++; // skip le '$'
	while (data->line && ft_isalpha(data->line[*i]) && data->line[*i])
	{
		name_variable[j] = data->line[*i];
		(*i)++;
		j++;
	}
	name_variable[j] = '\0';
	printf("name variable : %s\n", name_variable);
	return (name_variable);
}
