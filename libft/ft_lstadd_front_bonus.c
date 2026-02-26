/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:06:25 by amkhelif          #+#    #+#             */
/*   Updated: 2026/02/26 12:57:31 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//  met la nouvelle tete en tete de liste
// fait pointer new->next a lancienne tete

void	ft_lstadd_front(t_garbage **lst, t_garbage *new)
{
	new->next = *lst;
	*lst = new;
}
