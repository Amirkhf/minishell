/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:47:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/13 15:27:13 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	my_ft_isalpha(char c);

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
	while (data->line && my_ft_isalpha(data->line[*i]) && data->line[*i])
	{
		name_variable[j] = data->line[*i];
		(*i)++;
		j++;
	}
	name_variable[j] = '\0';
	printf("name variable : %s\n", name_variable);
	return (name_variable);
}

static int	my_ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '-')
		return (1);
	return (0);
}
