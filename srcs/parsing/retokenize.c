/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:13:40 by amary             #+#    #+#             */
/*   Updated: 2026/03/30 17:13:55 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	retokenize_expanded_str(t_data *data, t_token **token, char *str)
{
	char	**split;
	t_token	*new;
	int		i;

	split = ft_split(data, str, ' ');
	if (!split)
		return ;
	(*token)->str = split[0];
	i = 0;
	while (split[++i])
	{
		new = my_malloc(data, sizeof(t_token), TMP);
		if (!new)
			return ;
		new->str = split[i];
		new->type = 3;
		new->next = (*token)->next;
		new->prev = *token;
		if ((*token)->next)
			(*token)->next->prev = new;
		(*token)->next = new;
		*token = new;
	}
}
