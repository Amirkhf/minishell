/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:45:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/04 16:21:48 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Extrait un mot de la ligne
int	take_cmd(t_data *data, t_token **token_lst, char *str, int *i)
{
	char	*word;
	int		j;

	j = 0;
	word = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (word == NULL)
		return (0);
	while (str && str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '\t')
			break ;
		word[j] = str[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	if (!(add_token(data, token_lst, WORD, word)))
		return (0);
	return (1);
}

// Identifie et ajoute un opérateur (modifier cette fonction plus tard)
int	what_operator(char *str, int *i)
{
	if (!(ft_strncmp(str + *i, "<<", 2)))
		return (HEREDOC);
	else if (!(ft_strncmp(str + *i, ">>", 2)))
		return (APPEND);
	else if (!(ft_strncmp(str + *i, ">", 1)))
		return (REDIR_OUT);
	else if (!(ft_strncmp(str + *i, "<", 1)))
		return (REDIR_IN);
	else if (!(ft_strncmp(str + *i, "|", 1)))
		return (PIPE);
	return (7);
}

//  Verifie si un caractere est un operateur shell (|, <, >)
bool	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

//  Verifie si un caractère est un espace ou tabulation
bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

// Ajoute un token à la liste
bool	add_token(t_data *data, t_token **token_lst, t_token_type type,
		char *value)
{
	t_token *new;
	t_token *tmp;

	new = new_token(data, value, type);
	if (!(new))
	{
		perror("");
		return (0);
	}
	if (*token_lst == NULL)
	{
		(*token_lst) = new;
		new->prev = NULL;
		return (1);
	}
	tmp = *token_lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	return (1);
}
