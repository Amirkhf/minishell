/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:51:48 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/06 16:52:46 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	syntax_error(char *str)
{
	write(2, "minishell: syntax error near unexpected token `", 43);
	write(2, str, ft_strlen(str));
	write(2, "\'\n", 2);
}

void	msg_error_quote(void)
{
	write(2, "minishell: syntax error: unclosed quotes\n", 42);
}