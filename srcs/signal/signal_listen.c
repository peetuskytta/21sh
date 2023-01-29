/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_listen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:15:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/29 16:12:00 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

extern t_shell	*g_shell;

static void	signal_abort(int signo)
{
	kill(signo, SIGABRT);
	ft_putchar_fd('\n', STDOUT_FILENO);
	cmd_line_prompt(EOF);
	key_is_ctrlc(g_shell, &g_shell->window);
}

static void	signal_handler(int signo)
{
	if (signo == SIGCHLD)
		signal_abort(signo);
	else
		signal_abort(signo);
}

void	signal_listen(void)
{
	signal(SIGINT, signal_handler);
	//signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
}
