/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:39:45 by amary             #+#    #+#             */
/*   Updated: 2026/03/24 12:40:40 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>
#include <readline/readline.h> // Indispensable pour les fonctions rl_*

// 1. La fonction qui réagit quand on appuie sur Ctrl+C
void	handle_sigint(int sig)
{
	(void)sig; // On ne se sert pas du numéro du signal
	
	write(1, "\n", 1); // On saute une ligne
	
	// Magie de Readline pour réafficher le prompt proprement
	rl_on_new_line();      // Dit à readline qu'on est sur une nouvelle ligne
	rl_replace_line("", 0); // Efface ce que l'utilisateur était en train d'écrire
	rl_redisplay();        // Réaffiche "Minishell : "
}

// 2. La fonction pour brancher nos signaux
void	setup_signals(void)
{
	// Quand le système reçoit SIGINT (Ctrl+C), il appelle handle_sigint
	signal(SIGINT, handle_sigint);
	
	// Quand le système reçoit SIGQUIT (Ctrl+\), on lui dit de l'ignorer (SIG_IGN)
	signal(SIGQUIT, SIG_IGN);
}
