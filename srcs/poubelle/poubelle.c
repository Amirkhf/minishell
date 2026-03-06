
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