/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:29:06 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 13:21:31 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	char				**env;
	t_garbage			*head;
}						t_data;

// init struct
void					init_struct_data(t_data *data, char **env);

// parsing
void					extract_path(t_data *data, char **env);
// libft
char					**ft_split(char const *s, char c);
void					free_function(char **str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strlen(const char *s);
t_garbage				*ft_lstnew(void *content, int type);
void					ft_push_front(t_garbage **head, void *data, int type);

// exec

// utils
void					add_tab_free(t_data *data, char *str,
							char **double_str);
#endif