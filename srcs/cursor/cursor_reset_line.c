/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_reset_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:46:15 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/13 16:42:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_reset_line(t_win *window, int len)
{
	int	y;

	y = window->current_row - 1;
	tputs(tgoto(tgetstr("cm", NULL), len, y), 1, stdin_char);
	tputs(tgoto(tgetstr("cd", NULL), len, y), 1, stdin_char);
}
