/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_heredoc2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:16:21 by amary             #+#    #+#             */
/*   Updated: 2026/03/26 19:19:48 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_child(int fd, t_redir *redir)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	while (1)
	{
		line = readline("> ");
		if (!line || (ft_strncmp(line, redir->file, ft_strlen(redir->file)) == 0
				&& ft_strlen(line) == ft_strlen(redir->file)))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	exit(0);
}

int	action_heredoc2(t_redir *redir)
{
	int		fd;
	pid_t	pid;
	int		status;

	fd = open("/tmp/.minishell_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
		heredoc_child(fd, redir);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_signals();
	close(fd);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		return (write(1, "\n", 1), -1);
	return (open("/tmp/.minishell_heredoc", O_RDONLY));
}
