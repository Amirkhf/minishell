/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:23:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 11:48:48 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_double_quote(char *str)
{
	int i;

	printf("je suis dans la fonction is_double_quote\n");
	i = 0;
	if (str[i] == '"')
	{
		while (str[++i])
		{
			if (str[i] == '"')
				return (1);
		}
	}
	return (0);
}

int is_variable_env(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

char *extract_before_variable(t_data *data, char *str, int len, int *i)
{
	char *new_str;
	int j;

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

char *fill_expanded_str(t_data *data, char *str, int len, char *name_variale)
{
	char *new_str;
	char *env_value;
	int i;
	int j;

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
	// recupere ce quil y a droite
	return (new_str);
}

// fonction qui copie la valeur de la vraible denvironnement dans une string
char *extract_env_value(t_data *data, char *name_variable, int len)
{

	char *env_value;
	int i;
	int j;
	int a;

	a = 0;
	i = 0;
	env_value = my_malloc(data, len + 2, TMP);
	if (!(env_value))
		return (NULL);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], name_variable, ft_strlen(name_variable) + 1))
		{
			j = ft_strlen(name_variable) + 1;
			while (data->env[i][j])
			{
				env_value[a] = data->env[i][j];
				j++;
				a++;
			}
			env_value[a] = '\0';
		}
		i++;
	}
	return (env_value);
}

// enlever les quote de la str
char *extract_quote(t_data *data, char *str)
{
	int i;
	int j;
	char *new_str;

	printf("je suis dans la fonction extract_variable\n");
	j = 0;
	i = 0;
	new_str = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (new_str == NULL)
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	while (str[i])
	{
		if (!(str[i] == '"'))
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	// printf("%s\n", new_str);
	return (new_str);
}

// extrait le nom de la variable
char *extract_var_name(t_data *data, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	char *name_variable;

	name_variable = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (!(name_variable))
		return (NULL);
	while (str && !(str[i] == '$'))
		i++;
	while (str && !(str[i] == ' '))
	{
		name_variable[j] = str[i];
		i++;
		j++;
	}
	name_variable[j] = '\0';
	return (name_variable);
}



