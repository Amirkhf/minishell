/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 15:46:35 by amkhelif         ###   ########.fr       */
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
#endif