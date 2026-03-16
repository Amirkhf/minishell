/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:45:08 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/16 14:15:00 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*take_quote(t_data *data, int *i, int *j, char *word);

// Extrait un mot de la ligne
int	take_cmd(t_data *data, int *i)
{
	char	*word;
	int		j;

	j = 0;
	word = my_malloc(data, ft_strlen(data->line) + 2, TMP);
	if (!(word))
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	while (data->line[*i] && !is_operator(data->line + *i))
	{
		if (data->line[*i] == DOUBLE_QUOTE_C
			|| data->line[*i] == SIMPLE_QUOTE_C)
			take_quote(data, i, &j, word);
		if (is_space(data->line[*i]))
			break ;
		word[j] = data->line[*i];
		if (!data->line[*i])
			break ;
		j++;
		(*i)++;
	}
	word[j] = '\0';
	if (data->last_token && data->last_token->type != CMD
		&& data->last_token->type != PIPE)
		add_token(data, &data->token, CMD, word);
	else
		add_token(data, &data->token, ARGV, word);
	return (1);
}

bool	is_operator(char *line)
{
	if (!(strncmp(line, HEREDOC_C, 2)))
		return (1);
	else if (!(strncmp(line, APPEND_C, 2)))
		return (1);
	else if (!(strncmp(line, PIPE_C, 1)))
		return (1);
	else if (!(strncmp(line, REDIR_IN_C, 1)))
		return (1);
	else if (!(strncmp(line, REDIR_OUT_C, 1)))
		return (1);
	return (0);
}

// recupere a partir de linput tout le texte entre les quote
static char	*take_quote(t_data *data, int *i, int *j, char *word)
{
	char	quote;

	quote = data->line[*i];
	word[(*j)++] = quote;
	(*i)++;
	while (data->line[*i] && data->line[*i] != quote)
	{
		word[*j] = data->line[*i];
		(*j)++;
		(*i)++;
	}
	(*i)++;
	word[(*j)++] = quote;
	word[*j] = '\0';
	return (word);
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
	data->last_token = new;
	return (1);
}
