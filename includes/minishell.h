/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/10 17:52:04 by amkhelif         ###   ########.fr       */
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

# define TMP 0
# define PERM 1
# define QUOTE '"'
# define SIMPLE_QUOTE_C '\''
# define DOUBLE_QUOTE_C '\"'
# define HEREDOC_C "<<"
# define APPEND_C ">>"
# define REDIR_OUT_C ">"
# define REDIR_IN_C "<"
# define PIPE_C "|"

typedef enum e_token_type
{
	ARGV,
	CMD,
	SIMPLE_QUOTE,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND
}						t_token_type;

typedef struct s_token
{
	char				*str;
	char				*expander;
	t_token_type		type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

// struct for garbage_collector
typedef struct s_garbage
{
	void				*data;
	struct s_garbage	*next;
}						t_garbage;

// contains the variable env
typedef struct s_data
{
	char				*line;
	char				**env;
	t_garbage			*garbage_tmp;
	t_token				*last_token;
	t_garbage			*garbage_perm;
	t_token *token; // liste de token
}						t_data;

int						is_simple_quote(char *str);
int						ft_isalpha(int c);
long long				expanded_len(t_data *data, char *str,
							char *name_variable);
char					*extract_env_value(t_data *data, char *name_variable,
							int len);
char					*extract_var_name(t_data *data, char *str);
char					*extract_quote(t_data *data, char *str);
char					*extract_var_name(t_data *data, char *str);
char					**extract_env(t_data *data, char **env);
char					**ft_split(t_data *data, char const *s, char c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strdup(t_data *data, const char *s);
int						check_lexer(t_token **token);
int						parsing(t_data *data, t_token **token);
void					print_double_tab(char **str);
int						init_struct(t_data *data, char **env);
int						expander(t_data *data, t_token **token);
int						is_double_quote(char *str);
long long				ft_double_str_len(char **str);
void					*my_malloc(t_data *data, size_t size, bool type);
void					gc_add(t_garbage **lst, void *data);
void					free_all(t_garbage **gc);
size_t					ft_strlen(const char *s);
t_token					*new_token(t_data *data, char *str, t_token_type type);
void					token_add_back(t_data *data, t_token **head,
							t_token *new);
int						is_variable_env(char *str);
t_token					*token_line(t_data *data);
int						my_readline(t_data *data, char **env);
void					syntax_error(char *str);
void					my_exit(t_garbage **gc_tmp, t_garbage **gc_perm,
							int exit_status);
t_garbage				*ft_lstnew_gc(void *value);
char					*ft_strjoin(t_data *data, char const *s1,
							char const *s2);
bool					is_space(char c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
bool					add_token(t_data *data, t_token **token_lst,
							t_token_type type, char *value);
bool					is_operator(char *line);
char					*take_quote(t_data *data, int *i, int *j, char *word);
int						take_cmd(t_data *data, int *i);
void					syntax_error(char *str);
void					print_token(t_data *data);
int						ft_lstsize_lexer(t_token *lst);
void					msg_error_quote(void);
#endif