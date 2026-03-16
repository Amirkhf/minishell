/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:47:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/16 12:13:35 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	my_ft_isalpha(char c);

// extrait le nom de la variable
char	*extract_var_name(t_data *data, char *str, int *i)
{
	int		j;
	char	*name_variable;

	j = 0;
	name_variable = my_malloc(data, ft_strlen(data->line) + 1, TMP);
	if (!(name_variable))
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	(*i)++; // skip le '$'
	while (str && my_ft_isalpha(str[*i]) && str[*i])
	{
		name_variable[j] = str[*i];
		(*i)++;
		j++;
	}
	name_variable[j] = '\0';
	return (name_variable);
}

static int	my_ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '-')
		return (1);
	return (0);
}
