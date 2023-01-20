/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:06:54 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/13 16:21:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_window(t_shell *shell, t_win *window)
{
	struct winsize	win;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	window->cols = win.ws_col;
	window->rows = win.ws_row;
	window->win = &win;
	window->loc = 3;
	window->idx = 0;
	ft_memset(window->row_idx, 0, (sizeof(char *) * MAX_BUFF));
	window->row_idx[window->idx] = &shell->cmd_line[0];
}
