/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:43:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 12:58:10 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*extract_variable(t_data *data, char *str);
static char	*fill_expanded_str(t_data *data, char *str, int len,
				char *name_variale);
static char	*extract_before_variable(t_data *data, char *str, int len, int *i);
static char	*extract_after_varaiable(t_data *data, char *str, int *i);

// plus tard
int	expander(t_data *data, t_token **token)
{
	t_token	*tmp;

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

// fonction principal qui va cree la valeur a partie de ca $
static char	*extract_variable(t_data *data, char *str)
{
	bool		no_exist;
	char		*new_value;
	char		*name;
	long long	len_expanded;

	new_value = NULL;
	no_exist = 0;
	name = extract_var_name(data, str);
	if (!(name))
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	len_expanded = expanded_len(data, str, name);
	if (len_expanded < 0)
		no_exist = 1;
	new_value = fill_expanded_str(data, str, len_expanded, name);
	if (!(new_value))
		return (NULL);
	return (new_value);
}

static char	*fill_expanded_str(t_data *data, char *str, int len,
		char *name_variale)
{
	char	*new_str;
	char	*env_value;
	int		i;
	int		j;

	j = 0;
	i = 0;
	env_value = NULL;
	new_str = extract_before_variable(data, str, len, &i);
	if (!(new_str))
		return (NULL);
	if (str[i] == '$')
		env_value = extract_env_value(data, name_variale, len);
	if (env_value)
	{
		new_str = ft_strjoin(new_str, env_value);
		if (!(new_str))
			return (NULL);
	}
	env_value = NULL;
	if (!(str[i + ft_strlen(name_variale) + 1] == '\0') && str[i
		+ ft_strlen(name_variale) + 1] == '$')
	{
		env_value = extract_after_varaiable(data, str, &i);
		if (!(env_value))
			return (NULL);
	}
	return (new_str);
}

static char	*extract_before_variable(t_data *data, char *str, int len, int *i)
{
	char	*new_str;
	int		j;

	j = 0;
	new_str = my_malloc(data, len + ft_strlen(str) + 2, TMP);
	if (!(new_str))
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	while (str && !(str[*i] == '$'))
	{
		new_str[j] = str[*i];
		(*i)++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*extract_after_varaiable(t_data *data, char *str, int *i)
{
	char	*new_str;
	int		j;

	j = 0;
	new_str = my_malloc(data, ft_strlen(str) + 2, TMP);
	if (!(new_str))
		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
	while (!(str[*i] == '$')) // skip le le $variable
		(*i)++;
	while (str[*i] && !(str[*i] == '$')) // prend tout jusque la fin ou $
	{
		new_str[j] = str[*i];
		j++;
		(*i)++;
	}
	new_str[j] = '\0';
	return (new_str);
}
