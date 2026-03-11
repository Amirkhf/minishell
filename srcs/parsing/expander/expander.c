/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:43:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/11 15:26:10 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expander(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	data->new_line = my_malloc(data, expanded_len(data), TMP);
	if (!(data->new_line))
		my_exit(data->garbage_tmp, data->garbage_perm, EXIT_FAILURE);
	while (data->line[i])
	{
		if (data->line[i] == '$' && !(is_simple_quote(data->line, i)))
		{
			extract_var_env(data, &j, &i,extract_var_name(data,&i));
		}
		else
			data->new_line[++j] = data->line[i];
		i++;
	}
}


// verifier si le $ est entre des simple quote
int	is_simple_quote(char *str, int index_dollard)
{
	int	j;
	int	in_single_quote;
	int	in_double_quote;

	j = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (j < index_dollard)
	{
		if (str[j] == '\'' && in_double_quote == 0)
			in_single_quote = !in_single_quote;
		else if (str[j] == '"' && in_single_quote == 0)
			in_double_quote = !in_double_quote;
		j++;
	}
	return (in_single_quote);
}

// void extract_var_env(char *new_line, char *line, int *j, int *i)
// {
// 	(*i)++;
// 	while (line[*i] && line[*i] )
// 	{
// 		(*j)++;
// 		(*i)++;
// 	}

// }
// the plan for expander is
// parcour la line est verifie si on a

// this function is a function principal
// of the  part expander
// char	*expander(t_data *data)
// {
// 	int		i;
// 	char	*new_line;

// 	new_line = my_malloc(data, expanded_len(data) + 1, TMP);
// 	if (!(new_line))
// 		my_exit(data->garbage_tmp, data->garbage_perm, EXIT_FAILURE);
// 	i = 0;
// 	while (data->line[i])
// 	{
// 		if (data->line[i] == '$')
// 		{
// 			get_env_variable_string(data, &i)
// 		}

// 	}
// }

// char	*get_env_variable_string(t_data *data, int *i)
// {
// 	while (*i >= 0 && data->env[*i] != ' ' && data->env)
// 	{

// 	}
// }

// static char	*extract_variable(t_data *data, char *str);
// static char	*fill_expanded_str(t_data *data, char *str, int len,
// 				char *name_variale);
// static char	*extract_before_variable(t_data *data, char *str, int len,
// eint *i);
// static char	*extract_after_varaiable(t_data *data, char *str, int *i);

// // plus tard
// int	expander(t_data *data, t_token **token)
// {
// 	t_token	*tmp;

// 	printf("je suis dans la fonction expander\n");
// 	tmp = *token;
// 	while (tmp)
// 	{
// 		if (!(is_simple_quote(tmp->str)) && !(is_variable_env(tmp->str)))
// 		{
// 			if (is_double_quote(tmp->str))
// 			{
// 				tmp->str = extract_quote(data, tmp->str);
// 				if (!(tmp->str))
// 					return (EXIT_FAILURE);
// 			}
// 			tmp->str = extract_variable(data, tmp->str);
// 			if (!(tmp->str))
// 				return (EXIT_FAILURE);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (EXIT_SUCCESS);
// }

// // fonction principal qui va cree la valeur a partie de ca $
// static char	*extract_variable(t_data *data, char *str)
// {
// 	char		*new_value;
// 	char		*name;
// 	long long	len_expanded;

// 	// bool		no_exist;
// 	new_value = NULL;
// 	// no_exist = 0;
// 	name = extract_var_name(data, str);
// 	if (!(name))
// 		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
// 	len_expanded = expanded_len(data, str, name);
// 	// if (len_expanded == 0)
// 	// 	no_exist = 1;
// 	new_value = fill_expanded_str(data, str, len_expanded, name);
// 	if (!(new_value))
// 		return (NULL);
// 	return (new_value);
// }

// static char	*fill_expanded_str(t_data *data, char *str, int len,
// 		char *name_variale)
// {
// 	char	*new_str;
// 	char	*env_value;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	env_value = NULL;
// 	new_str = extract_before_variable(data, str, len, &i);
// 	if (!(new_str))
// 		return (NULL);
// 	if (str[i] == '$')
// 		env_value = extract_env_value(data, name_variale, len);
// 	printf("%s\n", env_value);
// 	if (env_value)
// 	{
// 		new_str = ft_strjoin(data, new_str, env_value);
// 		if (!(new_str))
// 			return (NULL);
// 	}
// 	env_value = NULL;
// 	if (!(str[i + ft_strlen(name_variale) + 1] == '\0') && !(str[i
// 			+ ft_strlen(name_variale) + 1] == '$'))
// 	{
// 		env_value = extract_after_varaiable(data, str, &i);
// 		if (!(env_value))
// 			return (NULL);
// 	}
// 	return (new_str);
// }

// static char	*extract_before_variable(t_data *data, char *str, int len,
//	int *i)
// {
// 	char	*new_str;
// 	int		j;

// 	j = 0;
// 	new_str = my_malloc(data, len + ft_strlen(str) + 2, TMP);
// 	if (!(new_str))
// 		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
// 	while (str && !(str[*i] == '$'))
// 	{
// 		new_str[j] = str[*i];
// 		(*i)++;
// 		j++;
// 	}
// 	new_str[j] = '\0';
// 	return (new_str);
// }

// static char	*extract_after_varaiable(t_data *data, char *str, int *i)
// {
// 	char	*new_str;
// 	int		j;

// 	j = 0;
// 	new_str = my_malloc(data, ft_strlen(str) + 2, TMP);
// 	if (!(new_str))
// 		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
// 	while (!(str[*i] == '$')) // skip le le $variable
// 		(*i)++;
// 	while (str[*i] && !(str[*i] == '$')) // prend tout jusque la fin ou $
// 	{
// 		new_str[j] = str[*i];
// 		j++;
// 		(*i)++;
// 	}
// 	new_str[j] = '\0';
// 	return (new_str);
// }
