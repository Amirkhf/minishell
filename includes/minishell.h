/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 18:18:41 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define STRING 0
# define DBL_STRING 1

// struct for garbage_collector
typedef struct s_garbage
{
	bool				is_2d_array;
	void				*data;
	struct s_garbage	*next;
}						t_garbage;

// struct for lexer

typedef enum s_lexer_type
{
	PIPE,
	INFILE,
	OUTFILE,
	REDIR_IN,
	REDIR_OUT,
	CMD,
	HERDOC
}						t_lexer_type;

typedef struct s_token
{
	char				*value;
	t_lexer_type		*type;
	struct s_token		*next;
}						t_token;

// contains the variable env
typedef struct s_data
{
	char *line; // contains input
	char				**env;
	t_garbage *lst_free; // for free
}						t_data;

// init struct
void					init_struct(t_data *data, char **env);

// parsing

// libft
char					**ft_split(char const *s, char c);
void					free_function(char **str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					gc_add(t_garbage **head, void *data, int type);
size_t					ft_strlen(const char *s);
t_garbage				*ft_lstnew(t_data *data, void *value, int type);
t_token					*lst_new_token(t_garbage **head_gc, t_lexer_type *type,
							char *value);
// free
void					free_all(t_garbage *lst);
void					*my_malloc(t_garbage **head_gc, int len);
// lexer
bool					verif_quote(char *line);
bool					space_or_tab(char c);
bool					is_sign(char c);
void					add_token(t_garbage **head_gc, t_token **head_token,
							t_lexer_type type, char *value);
t_lexer_type			token_type(char c);
char					*take_cmd(t_data *data, char *line, int i);

char					*token_line(t_data *data, t_token *token, char *line);
// main
void					loop(t_data *data);
#endif