/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:43:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/13 14:35:07 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expander(t_data *data)
{
	long long	len;
	int			i;
	int			j;
	int			a;

	a = 0;
	j = 0;
	i = 0;
	len = expanded_len(data);
	data->new_line = my_malloc(data, len + 1, TMP);
	if (!(data->new_line))
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	while (data->line[i])
	{
		if (data->line[i] == '$' && !(is_simple_quote(data->line, i)))
		{
			a = i;
			copy_env_value(data, &i, &j, extract_var_name(data, &a));
		}
		if (data->line[i] != '\'')
			data->new_line[j++] = data->line[i++];
		else
		{
			i++;
			j++;
		}
	}
	return (data->new_line[j] = '\0', data->new_line);
}

void	copy_env_value(t_data *data, int *i, int *j, char *name_variable)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (data->env[a])
	{
		if (ft_strncmp(data->env[a], name_variable,
				ft_strlen(name_variable)) == 0)
		{
			b += ft_strlen(name_variable) + 1;
			while (data->env[a][b])
			{
				data->new_line[*j] = data->env[a][b];
				(*j)++;
				b++;
			}
			break ;
		}
		a++;
	}
	(*i) += ft_strlen(name_variable) + 1;
}

void	copy_name_variable(t_data *data, int *i, int *j, char *name_variable)
{
	int	a;

	a = 0;
	while (name_variable[a])
	{
		data->new_line[*j] = name_variable[a];
		(*j)++;
		a++;
	}
}

//  verifier si le $ est entre des simple quote
int	is_simple_quote(char *str, int index_dollar)
{
	int	j;
	int	in_single_quote;
	int	in_double_quote;

	j = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (j < index_dollar)
	{
		if (str[j] == '\'' && in_double_quote == 0)
			in_single_quote = !in_single_quote;
		else if (str[j] == '"' && in_single_quote == 0)
			in_double_quote = !in_double_quote;
		j++;
	}
	return (in_single_quote);
}

