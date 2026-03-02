/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/02 12:03:58 by amkhelif         ###   ########.fr       */
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

# define STRING 0     // nous sert dans notre gc
# define DBL_STRING 1 // nous sert dans notre gc

// struct for garbage_collector
typedef struct s_garbage
{
	bool is_2d_array; // is a double char ?
	void				*data;
	struct s_garbage	*next;
}						t_garbage;

// struct for lexer

typedef enum s_token_type
{
	PIPE,
	CMD,
	REDIR_IN,
	REDIRECTION_IN,
	REDIRECTION_OUT,
	INFILE,
	OUTFILE,
}						t_token_type;

typedef struct s_token
{
	char				*value;
	t_token_type		type;
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
size_t					ft_strlen(const char *s);
t_garbage				*ft_lstnew(void *content, int type);
void					gc_add(t_garbage **head, void *data, int type);

// free
void					free_all(t_garbage *lst);

// lexer
int						lexer_funtion(t_garbage **lst_free, t_token *token,
							char *line);
t_token					*lst_new_token(t_garbage **free_lst, char *value,
							char *type);
void					add_token(t_token **head, t_garbage **lst_free,
							char *value, char *type);
void					add_token(t_token **head, t_garbage **lst_free,
							char *value, t_token_type *type);

// main
void					loop(t_garbage *garbage, t_data *data);
#endif