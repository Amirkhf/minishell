/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:42 by amkhelif          #+#    #+#             */
/*   Updated: 2026/03/05 16:51:07 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Alloue de la mémoire et l'ajoute au GC
void	*my_malloc(t_data *data, size_t size, bool type)
{
	void	*memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	if (type == TMP)
		gc_add(&data->garbage_tmp, memory);
	else
		gc_add(&data->garbage_perm, memory);
	return (memory);
}

// Ajoute un bloc mémoire au GC
void	gc_add(t_garbage **lst, void *data)
{
	t_garbage	*node;

	node = ft_lstnew_gc(data);
	if (!node)
	{
		free(data);
		perror("minishell: malloc failed");
		exit(1); // remlplace par free_all plus tard
	}
	node->next = *lst;
	*lst = node;
}

// Affiche les tokens pour le débogage
void	print_token(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		printf("--------------------\n");
		printf("Value : [%s]\n", tmp->str);
		printf("Type  : %d\n", tmp->type);
		tmp = tmp->next;
	}
	printf("--------------------\n");
}



// #include "../../inc/minishell.h"

// void    print_redir(t_redir *redir)
// {
//     while (redir)
//     {
//         printf("      REDIR type=%d file=%s\n",
//             redir->type,
//             redir->file);
//         redir = redir->next;
//     }
// }

// void    print_cmd(t_cmd *cmd)
// {
//     int    i;
//     int    cmd_index;

//     cmd_index = 0;
//     while (cmd)
//     {
//         printf("CMD [%d]\n", cmd_index++);
//         i = 0;
//         if (cmd->arg_cmd)
//         {
//             while (cmd->arg_cmd[i])
//             {
//                 printf("   ARG[%d] = %s\n", i, cmd->arg_cmd[i]);
//                 i++;
//             }
//         }
//         else
//             printf("   (no args)\n");
//         if (cmd->redir)
//             print_redir(cmd->redir);
//         else
//             printf("      (no redir)\n");
//         printf("--------------\n");
//         cmd = cmd->next;
//     }
// }
// -----------------------------------------------------------------------------------