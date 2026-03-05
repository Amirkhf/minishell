/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:45:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/05 16:59:38 by amkhelif         ###   ########.fr       */
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
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	if (str[*i] == DOUBLE_QUOTE_c || str[*i] == SIMPLE_QUOTE_c)
	{
		word = take_quote(data, str, i, str[*i], &j);
		if (word == NULL)
			return (msg_error_quote(), 0);
	}
	while (str[*i] && !is_space(str[*i]) && !is_operator(str[*i]))
	{
		if (is_space(str[*i]))
			break ;
		word[j] = str[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	add_token(data, token_lst, CMD, word);
	return (1);
}

// recupere a partir de linput tout le texte entre les quote
//
char	*take_quote(t_data *data, char *str, int *i, char type_QUOTE, int *j)
{
	char	*word;

	(*i)++;
	if (str[*i] == type_QUOTE)
		return (NULL);
	word = my_malloc(data, ft_strlen(str) + 1, TMP);
	if (!(word))
		return (NULL);
	while (str[*i] && str[*i] != type_QUOTE)
	{
		word[*j] = str[*i];
		(*j)++;
		(*i)++;
	}
	if (str[*i] == '\0')
		return (NULL);
	(*i)++;
	word[*j] = '\0';
	return (word);
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
	t_token	*new;
	t_token	*tmp;

	new = new_token(data, value, type);
	if (!(new))
	{
		perror("");
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
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
