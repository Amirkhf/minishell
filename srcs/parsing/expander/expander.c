/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:43:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:37:47 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/minishell.h"

static char	*expand_word(t_data *data, char *str);
static void	expand_exit_status(t_data *data, char *new_str, int *i, int *j);

char	*expander(t_data *data)
{
	t_token	*tmp;
	char	*expanded_str;

	tmp = data->token;
	while (tmp)
	{
		if ((!tmp->prev || tmp->prev->type != HEREDOC)
			&& is_variable_env(tmp->str) == EXIT_SUCCESS)
		{
			expanded_str = expand_word(data, tmp->str);
			if (ft_strchr(expanded_str, ' ') && !is_in_quotes(tmp->str))
				retokenize_expanded_str(data, &tmp, expanded_str);
			else
				tmp->str = expanded_str;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	copy_env_value(t_data *data, char *new_str, int *j, char *var)
{
	int	len;
	int	a;
	int	b;

	len = ft_strlen(var);
	a = -1;
	while (data->env[++a])
	{
		if (ft_strncmp(data->env[a], var, len) == 0
			&& data->env[a][len] == '=')
		{
			b = len + 1;
			while (data->env[a][b])
				new_str[(*j)++] = data->env[a][b++];
			break ;
		}
	}
	return (len + 1);
}

static void	expand_exit_status(t_data *data, char *nstr, int *i, int *j)
{
	char	*status_str;
	int		k;

	status_str = ft_itoa(data, data->exit_status);
	k = -1;
	while (status_str[++k])
		nstr[(*j)++] = status_str[k];
	(*i) += 2;
}

int	is_simple_quote(char *str, int index_dollar)
{
	int	j;
	int	in_single;
	int	in_double;

	j = -1;
	in_single = 0;
	in_double = 0;
	while (++j < index_dollar)
	{
		if (str[j] == '\'' && in_double == 0)
			in_single = !in_single;
		else if (str[j] == '"' && in_single == 0)
			in_double = !in_double;
	}
	return (in_single);
}

static char	*expand_word(t_data *data, char *str)
{
	int		i;
	int		j;
	int		a;
	char	*nstr;

	i = 0;
	j = 0;
	nstr = my_malloc(data, expanded_len(data, str) + 1, TMP);
	if (!nstr)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && !is_simple_quote(str, i) && str[i + 1] == '?')
			expand_exit_status(data, nstr, &i, &j);
		else if (str[i] == '$' && !is_simple_quote(str, i))
		{
			a = i;
			i += copy_env_value(data, nstr, &j,
					extract_var_name(data, str, &a));
		}
		else
			nstr[j++] = str[i++];
	}
	nstr[j] = '\0';
	return (nstr);
}

void	retokenize_expanded_str(t_data *data, t_token **token, char *str)
{
	char	**split_str;
	t_token	*new_token;
	t_token	*current;
	int		i;

	split_str = ft_split(data, str, ' ');
	if (!split_str)
		return ;
	(*token)->str = split_str[0];
	current = *token;
	i = 1;
	while (split_str[i])
	{
		new_token = my_malloc(data, sizeof(t_token), TMP);
		if (!new_token)
			return ;
		new_token->str = split_str[i];
		new_token->type = 3;
		new_token->next = current->next;
		new_token->prev = current;
		if (current->next)
			current->next->prev = new_token;
		current->next = new_token;
		current = new_token;
		i++;
	}
	*token = current;
}

int	is_in_quotes(char *str)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (str[i])
	{
		if (str[i] == '\'' && in_double == 0)
			in_single = !in_single;
		else if (str[i] == '"' && in_single == 0)
			in_double = !in_double;
		i++;
	}
	if (in_single || in_double)
		return (1);
	return (0);
}
