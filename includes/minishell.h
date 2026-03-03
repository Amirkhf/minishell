/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/03 13:38:49 by amkhelif         ###   ########.fr       */
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

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
}						t_token_type;

typedef struct s_token
{
	char				*str;
	t_token_type		type;
	struct s_token		*next;
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
	t_garbage			*garbage_perm;
}						t_data;

// init struct
void					init_struct(t_data *data, char **env);

// for garbage collector
t_garbage				*ft_lstnew_gc(void *value);
void					*my_malloc(t_data *data, size_t size, bool type);
void					gc_add(t_garbage **lst, void *data);
void					free_all(t_garbage **gc);
size_t					ft_strlen(const char *s);
t_token					*new_token(t_data *data, char *str, t_token_type *type);
void					token_add_back(t_token **head, t_token *new);
#endif