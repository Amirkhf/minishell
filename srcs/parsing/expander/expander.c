/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:43:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/24 15:53:37 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*expand_word(t_data *data, char *str);
static void	expand_exit_status(t_data *data, char *new_str, int *i, int *j);

char	*expander(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if ((tmp->prev == NULL || tmp->prev->type != HEREDOC)
			&& is_variable_env(tmp->str) == EXIT_SUCCESS)
		{
			tmp->str = expand_word(data, tmp->str);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static char	*expand_word(t_data *data, char *str)
{
	int		i;
	int		a;
	int		j;
	char	*new_str;

	i = 0;
	a = 0;
	j = 0;
	new_str = my_malloc(data, expanded_len(data, str) + 1, TMP);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && !(is_simple_quote(str, i)))
		{
			if (str[i + 1] == '?')
			{
				expand_exit_status(data, new_str, &i, &j);
				continue ;
			}
			a = i;
			copy_env_value(data, new_str, &i, &j, extract_var_name(data, str, &a));
			continue ;
		}
		new_str[j++] = str[i++];
	}
	return (new_str[j] = '\0', new_str);
}

void	copy_env_value(t_data *data, char *new_str, int *i, int *j,
		char *name_variable)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (data->env[a])
	{
		if (ft_strncmp(data->env[a], name_variable,
				ft_strlen(name_variable)) == 0
			&& data->env[a][ft_strlen(name_variable)] == '=')
		{
			b += ft_strlen(name_variable) + 1;
			while (data->env[a][b])
			{
				new_str[*j] = data->env[a][b];
				(*j)++;
				b++;
			}
			break ;
		}
		a++;
	}
	(*i) += ft_strlen(name_variable) + 1;
}

void	copy_name_variable(t_data *data, int *j, char *name_variable)
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

static void	expand_exit_status(t_data *data, char *new_str, int *i, int *j)
{
	char *status_str;
	int k;

	status_str = ft_itoa(data, data->exit_status);
	k = 0;
	while (status_str[k])
	{
		new_str[*j] = status_str[k];
		(*j)++;
		k++;
	}
	(*i) += 2;
}