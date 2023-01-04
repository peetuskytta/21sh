/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:06:54 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/04 14:45:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_window(t_win *window)
{
	struct winsize	win;

	init_row_idx(window);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	window->cols = win.ws_col;
	window->rows = win.ws_row;
	window->current_row = window->rows - 19;
	window->win = &win;
	window->loc = 3;
}
