/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:10:49 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/26 21:41:26 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_type_name(t_token_type type)
{
	if (type == CMD)
		return ("CMD");
	if (type == SIMPLE_QUOTE)
		return ("SIMPLE_QUOTE");
	if (type == PIPE)
		return ("PIPE");
	if (type == REDIR_IN)
		return ("REDIR_IN");
	if (type == REDIR_OUT)
		return ("REDIR_OUT");
	if (type == HEREDOC)
		return ("HEREDOC");
	if (type == APPEND)
		return ("APPEND");
	return ("UNKNOWN");
}

void	print_token(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	printf("\n=== LISTE DES TOKENS ===\n");
	while (tmp)
	{
		printf("Valeur : [%s] | Type : %s\n", tmp->str,
			get_type_name(tmp->type));
		tmp = tmp->next;
	}
	printf("========================\n\n");
}

void	print_double_tab(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("%d \n", i);
		i++;
	}
}

// recupere a partir de linput tout le texte entre les quote
//
// char	*take_quote(t_data *data, char *str, int *i, char type_QUOTE, int *j)
// {
// 	char	*word;

// 	// (*i)++;
// 	// if (str[*i] == type_QUOTE)
// 	// 	return (NULL);
// 	word = my_malloc(data, ft_strlen(str) + 1, TMP);
// 	if (!(word))
// 		return (NULL);
// 	while (str[*i])
// 	{
// 		if (str[*i] == type_QUOTE)
// 		{
// 			word[*j] = type_QUOTE;
// 			(*j)++;
// 			(*i)++;
// 			break ;
// 		}
// 		word[*j] = str[*i];
// 		(*j)++;
// 		(*i)++;
// 	}
// 	// if (str[*i] == '\0')
// 	// 	return (NULL);
// 	// (*i)++;
// 	word[*j] = '\0';
// 	return (word);
// }

// // verifie si on est entre des quote
// bool	is_in_quotes(char *line, int pos)
// {
// 	int	quote;
// 	int	save_pos;

// 	size_t len_line; // prendre ca en param pour la norm
// 	quote = 0;
// 	save_pos = pos;
// 	len_line = ft_strlen(line);
// 	if (save_pos == len_line)
// 		return (0);
// 	while (save_pos > 0)
// 	{
// 		if (line[save_pos] == SIMPLE_QUOTE_c)
// 			quote = 1;
// 		else if (line[save_pos] == DOUBLE_QUOTE_c)
// 			quote = 2;
// 		save_pos--;
// 	}
// 	while (quote > 0 && line[pos])
// 	{
// 		if (line[pos] == SIMPLE_QUOTE_c && quote == 1)
// 			return (1);
// 		else if (line[pos] == DOUBLE_QUOTE_c && quote == 2)
// 			return (1);
// 		pos++;
// 	}
// 	return (0);
// }