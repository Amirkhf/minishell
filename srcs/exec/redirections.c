/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:23:57 by amary             #+#    #+#             */
/*   Updated: 2026/03/25 15:22:06 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <fcntl.h>

int	action_heredoc2(t_redir *redir)
{
	int		fd;
	char	*line;
	int		saved_stdout;
	
	saved_stdout = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	fd = open("/tmp/.minishell_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
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
	dup2(saved_stdout, STDOUT_FILENO);
	return (close(saved_stdout), open("/tmp/.minishell_heredoc", O_RDONLY));
}

int	action_redirr(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(redir->file);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	action_redird(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(redir->file);
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	action_heredoc(t_redir *redir)
{
	int	fd;

	fd = action_heredoc2(redir);
	if (fd == -1)
	{
		perror("minishell: heredoc");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	handle_redirections(t_cmd *cmd)
{
	t_redir	*redir;
	int		fd;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == REDIR_OUT && action_redirr(redir) == 1)
			return (1);
		else if (redir->type == APPEND && action_redird(redir) == 1)
			return (1);
		else if (redir->type == REDIR_IN)
		{
			fd = open(redir->file, O_RDONLY);
			if (fd == -1)
				return (perror(redir->file), 1);
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (redir->type == HEREDOC && action_heredoc(redir) == 1)
			return (1);
		redir = redir->next;
	}
	return (0);
}
