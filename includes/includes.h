/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:12:41 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/24 17:39:23 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


// oublie pas ces cas la
//---------------------------------------------------
//  env -i < infile "grep e" | "ls" > out | echo $?
// 0
// env: ‘grep e’: No such file or directory
// env: use -[v]S to pass options in shebang lines
//ils est possible que la solution soitt au moment on
// on essaye de construit le path si on ne le trouve pas
//ecrire ce message env: ‘ls ’: No such file or directory
//return (0);
//---------------------------------------------------


// libft
void		free_function(char **str);
char		**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// parsing
void		take_path_exec(t_data *data, char **env);

typedef struct s_data
{
	char	**my_path;
	// contient tout les chemin de la variable denvironnement env
}			t_data;

#endif