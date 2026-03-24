/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:23:57 by amary             #+#    #+#             */
/*   Updated: 2026/03/24 12:05:54 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <fcntl.h>

int	action_heredoc2(t_redir *redir)
{
	int		fd;
	char	*line;

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
	return (open("/tmp/.minishell_heredoc", O_RDONLY));
}

void	action_redirr(int fd, t_redir *redir)
{
	fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(redir->file);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	action_redird(int fd, t_redir *redir)
{
	fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(redir->file);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	action_heredoc(int fd, t_redir *redir)
{
	fd = action_heredoc2(redir);
	if (fd == -1)
	{
		perror("minishell: heredoc");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return ;
}

void	handle_redirections(t_cmd *cmd)
{
	t_redir	*redir;
	int		fd;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == REDIR_OUT)
			action_redirr(fd, redir);
		else if (redir->type == APPEND)
			action_redird(fd, redir);
		else if (redir->type == REDIR_IN)
		{
			fd = open(redir->file, O_RDONLY);
			if (fd == -1)
			{
				perror(redir->file);
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (redir->type == HEREDOC)
			action_heredoc(fd, redir);
		redir = redir->next;
	}
}
