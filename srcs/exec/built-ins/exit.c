/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:01:15 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 19:46:43 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_valid_number(char *str, long long *res)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	*res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		*res = *res * 10 + (str[i++] - '0');
	}
	return (*res *= s, 1);
}

void	ft_exit(t_data *data, t_cmd *cmd)
{
	long long	exit_code;

	printf("exit\n");
	exit_code = data->exit_status;
	if (cmd->args[1])
	{
		if (!is_valid_number(cmd->args[1], &exit_code))
		{
			write(2, "minishell: exit: numeric argument required\n", 43);
			exit_code = 2;
		}
		else if (cmd->args[2])
		{
			write(2, "minishell: exit: too many arguments\n", 36);
			data->exit_status = 1;
			return ;
		}
	}
	free_all(&data->garbage_tmp);
	free_all(&data->garbage_perm);
	exit(exit_code % 256);
}
