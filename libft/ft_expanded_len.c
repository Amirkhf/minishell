/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanded_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:33:58 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:44:37 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	len_var_env(t_data *data, char *name_variable)
{
	int	i;
	int	a;
	int	len;

	len = 0;
	i = 0;
	a = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], name_variable,
				ft_strlen(name_variable)) == 0
			&& data->env[i][ft_strlen(name_variable)] == '=')
		{
			while (data->env[i][a] != '=')
				a++;
			while (data->env[i][a])
			{
				len++;
				a++;
			}
			break ;
		}
		i++;
	}
	return (len);
}

long long	expanded_len(t_data *data, char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			len += ft_strlen(ft_itoa(data, data->exit_status));
			i += 2;
			continue ;
		}
		if (str[i] == '$')
		{
			tmp = extract_var_name(data, str, &i);
			if (tmp)
				len += len_var_env(data, tmp);
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

// static long long	len_var_env(t_data *data, char *name_var_env);

// long long	expanded_len(t_data *data)
// {
// 	int		i;
// 	int		len;
// 	char	*name_var_env;

// 	len = 0;
// 	i = 0;
// 	name_var_env = my_malloc(data, ft_strlen(data->line), TMP);
// 	if (!(name_var_env))
// 		my_exit(&data->garbage_tmp, &data->garbage_perm, EXIT_FAILURE);
// 	while (data->line[i])
// 	{
// 		if (data->line[i] == '$')
// 		{
// 			extract_var_name(data, &i);
// 			len += len_var_env(data, name_var_env);
// 		}
// 		len++;
// 		i++;
// 	}
// 	return (len);
// }

// // this function calcul the len variable
// static long long	len_var_env(t_data *data, char *name_var_env)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	len = 0;
// 	j = 0;
// 	i = 0;
// 	printf("je suis dans len_var_env : %s\n", name_var_env);
// 	while (data->env[i])
// 	{
// 		if (ft_strncmp(data->env[i], name_var_env,
// 				ft_strlen(name_var_env)) == 0)
// 		{
// 			j = ft_strlen(name_var_env) + 1;
// 			while (data->env[i][j])
// 			{
// 				len++;
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (len);
// }
// // calcule la taille du contenue dune variable denvironnement
// long long	expanded_len(t_data *data, char *str, char *name_variable)
// {
// 	int i;
// 	int j;

// 	j = 0;
// 	i = 0;
// 	while (data->env[i])
// 	{
// 		if (ft_strncmp(data->env[i], name_variable,
// 				ft_strlen(name_variable)) == 0)
// 		{
// 			while ((data->env[i] + ft_strlen(name_variable) + 1)[j])
// 				j++;
// 			break ;
// 		}
// 		i++;
// 	}
// 	if (j == 0)
// 		return (0);
// 	return (j);
// }
// }