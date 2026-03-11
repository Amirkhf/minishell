/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:47:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/11 15:29:15 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// extrait le nom de la variable
char	*extract_var_name(t_data *data, char *str, char *name_variable, int *i)
{
	int		j;
	char	*name_variable;

	j = 0;
	name_variable = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (!(name_variable))
		my_exit(data->garbage_tmp, data->garbage_perm, EXIT_FAILURE);
	(*i)++; // skip le '$'
	while (data->line && ft_isalpha(data->line[*i]) && data->line[*i])
	{
		name_variable[j] = str[*i];
		(*i)++;
		j++;
	}
	name_variable[j] = '\0';
	return (name_variable);
}

// // fonction qui copie la valeur de la vraible denvironnement dans une string
// char	*extract_env_value(t_data *data, char *name_variable, int len)
// {
// 	char	*env_value;
// 	int		i;
// 	int		j;
// 	int		a;

// 	a = 0;
// 	i = 0;
// 	env_value = my_malloc(data, len + 1, TMP);
// 	if (!(env_value))
// 		return (NULL);
// 	while (len != 0 && data->env[i])
// 	{
// 		if (!ft_strncmp(data->env[i], name_variable, ft_strlen(name_variable)))
// 		{
// 			j = ft_strlen(name_variable) + 1;
// 			while (data->env[i][j])
// 			{
// 				printf("%c\n", data->env[i][j]);
// 				env_value[a] = data->env[i][j];
// 				j++;
// 				a++;
// 			}
// 			break ;
// 		}
// 		i++;
// 	}
// 	env_value[a] = '\0';
// 	return (env_value);
// }

// // enlever les quote de la str
// char	*extract_quote(t_data *data, char *str)
// {
// 	int		i;
// 	int		j;
// 	char	*new_str;

// 	printf("je suis dans la fonction extract_variable\n");
// 	j = 0;
// 	i = 0;
// 	new_str = my_malloc(data, ft_strlen(str) + 1, TMP);
// 	if (new_str == NULL)
// 		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
// 	while (str[i])
// 	{
// 		if (!(str[i] == '"'))
// 		{
// 			new_str[j] = str[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	new_str[j] = '\0';
// 	return (new_str);
// }
