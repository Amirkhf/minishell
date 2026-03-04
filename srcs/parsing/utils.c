/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:11:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 18:36:53 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	syntax_error(char *str)
{
	write(2, "bash: syntax error near unexpected token `", 43);
	write(2, &str, ft_strlen(str));
	write(2, "\'\n", 2);
}

// bash-5.1$ | ls
// bash: syntax error near unexpected token `|'
// bash-5.1$ < > ls
// bash: syntax error near unexpected token `>'
// bash-5.1$
// bash-5.1$ ls >
// bash: syntax error near unexpected token `newline'
// bash-5.1$