/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/24 17:49:11 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <limits.h>
# include <stdio.h>

# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
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
	t_token_type		type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_garbage
{
	void				*data;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_redir
{
	int type;   // REDIR_IN, REDIR_OUT, HEREDOC, APPEND
	char *file; // Le nom du fichier ou le délimiteur du heredoc
	struct s_redir		*next;
}						t_redir;

typedef struct s_cmd
{
	char **args;     // Le tableau pour execve
	t_redir *redirs; // La liste des redirections pour cette commande spécifique
	int fd_in;       // Fd pour l'entrée
	int fd_out;      // Fd pour la sortie
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_data
{
	char				*line;
	char				*new_line;
	char				**env;
	t_garbage			*garbage_tmp;
	t_garbage			*garbage_perm;
	t_token				*last_token;
	t_token				*token;
	int					exit_status;
	t_cmd				*cmds;
}						t_data;

char					*ft_itoa(t_data *data, int n);
void					remove_quote(t_data *data);
int						init_struct(t_data *data, char **env);
char					**extract_env(t_data *data, char **env);
void					*my_malloc(t_data *data, size_t size, bool type);
void					gc_add(t_garbage **lst, void *data);
void					free_all(t_garbage **gc);
void					my_exit(t_garbage **gc_tmp, t_garbage **gc_perm,
							int exit_status);
							void my_echo(t_data *data, t_cmd *cmd);
void					copy_env_value(t_data *data, char *new_str, int *i,
							int *j, char *name_variable);
t_garbage				*ft_lstnew_gc(void *value);
int						my_readline(t_data *data);
char					*ft_itoa(t_data *data, int n);
t_token					*token_line(t_data *data);
int						take_cmd(t_data *data, int *i);
bool					add_token(t_data *data, t_token **token_lst,
							t_token_type type, char *value);
bool					is_operator(char *line);
bool					is_space(char c);
char					*expander(t_data *data);
char					*extract_var_name(t_data *data, char *str, int *i);
int						is_simple_quote(char *str, int index_dollar);
int						is_double_quote(char *str);
int						is_variable_env(char *str);
char					**ft_split(t_data *data, char const *s, char c);
char					*ft_strdup(t_data *data, const char *s);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(t_data *data, char const *s1,
							char const *s2);
int						parsing(t_data *data, t_token **token);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strlen(const char *s);
long long				ft_double_str_len(char **str);
long long				expanded_len(t_data *data, char *str);
int						ft_isalpha(int c);
t_token					*new_token(t_data *data, char *str, t_token_type type);
void					token_add_back(t_data *data, t_token **head,
							t_token *new);
int						ft_lstsize_lexer(t_token *lst);
void					syntax_error(char *str);
void					msg_error_quote(void);
void					print_token(t_data *data);
void					print_double_tab(char **str);
void					ft_env(char **env);
void					ft_pwd(void);
void					build_cmds(t_data *data);
void					fill_cmd(t_data *data, t_cmd *cmd, t_token **tok_cpy);
int						count_args(t_token *token);
void					add_redir(t_data *data, t_cmd *cmd, int type,
							char *file);
t_cmd					*new_cmd(t_data *data);
char					*get_cmd_path(t_data *data, char *cmd_name);
char					*check(char *cmd_name, char **env);
char					*get_env_path(char **envp, char *key);
bool					has_slash(char *str);
void					my_exec(t_data *data);
void					exec_simple_cmd(t_data *data, t_cmd *cmd);
bool					is_builtin(char *cmd_name);
void					ft_cd(t_data *data, t_cmd *cmd);
void					ft_exit(t_data *data);
void					exec_builtin(t_data *data, t_cmd *cmd);
void					handle_redirections(t_cmd *cmd);
void					action_redird(int fd, t_redir *redir);
void					action_redirr(int fd, t_redir *redir);
void					action_HEREDOC(int fd, t_redir *redir);
#endif