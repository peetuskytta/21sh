/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_listen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:15:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/01 14:20:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

extern t_shell	*g_shell;

void	signal_win_handler(int signo)
{
	if (signo == SIGWINCH)
	{
	}
}

static void	signal_abort(int signo)
{
	g_shell->flg = 0;
	if (signo)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		cmd_line_prompt(EOF);
		key_is_ctrlc(g_shell, &g_shell->window);
	}
}

static void	signal_handler(int signo)
{
	signal_abort(signo);
}

void	signal_listen(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_win_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
}
