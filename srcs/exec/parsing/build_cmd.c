/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:38:15 by amary             #+#    #+#             */
/*   Updated: 2026/03/30 17:05:44 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_cmd	*new_cmd(t_data *data)
{
	t_cmd	*cmd;

	cmd = my_malloc(data, sizeof(t_cmd), TMP);
	if (!cmd)
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	cmd->next = NULL;
	return (cmd);
}

void	add_redir(t_data *data, t_cmd *cmd, int type, char *file)
{
	t_redir	*redir;
	t_redir	*tmp;

	redir = my_malloc(data, sizeof(t_redir), TMP);
	if (!redir)
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	redir->type = type;
	redir->file = file;
	redir->next = NULL;
	if (!cmd->redirs)
		cmd->redirs = redir;
	else
	{
		tmp = cmd->redirs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = redir;
	}
}

int	count_args(t_token *token)
{
	int	count;

	count = 0;
	while (token && token->type != PIPE)
	{
		if (token->type >= REDIR_IN && token->type <= APPEND)
		{
			token = token->next;
			if (token)
				token = token->next;
			continue ;
		}
		count++;
		token = token->next;
	}
	return (count);
}

void	fill_cmd(t_data *data, t_cmd *cmd, t_token **tok_cpy)
{
	int	i;
	int	count;

	i = 0;
	count = count_args(*tok_cpy);
	cmd->args = my_malloc(data, sizeof(char *) * (count + 1), TMP);
	if (!cmd->args)
		my_exit(&data->garbage_tmp, &data->garbage_perm, 1);
	while (*tok_cpy && (*tok_cpy)->type != PIPE)
	{
		if ((*tok_cpy)->type >= REDIR_IN && (*tok_cpy)->type <= APPEND)
		{
			add_redir(data, cmd, (*tok_cpy)->type, (*tok_cpy)->next->str);
			*tok_cpy = (*tok_cpy)->next->next;
			continue ;
		}
		if ((*tok_cpy)->str != NULL)
			cmd->args[i++] = (*tok_cpy)->str;
		*tok_cpy = (*tok_cpy)->next;
	}
	cmd->args[i] = NULL;
}

void	build_cmds(t_data *data)
{
	t_token	*tok_cpy;
	t_cmd	*head;
	t_cmd	*curr_cmd;

	tok_cpy = data->token;
	head = NULL;
	curr_cmd = NULL;
	data->cmds = NULL;
	while (tok_cpy)
	{
		if (!head)
		{
			head = new_cmd(data);
			curr_cmd = head;
		}
		else
		{
			curr_cmd->next = new_cmd(data);
			curr_cmd = curr_cmd->next;
		}
		fill_cmd(data, curr_cmd, &tok_cpy);
		if (tok_cpy && tok_cpy->type == PIPE)
			tok_cpy = tok_cpy->next;
	}
	data->cmds = head;
}
