/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/17 14:29:08 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_position(t_shell *shell, t_win *window, int ws)
{
	int	x;
	int y;

	x = shell->cmd_idx - ws;
	y = window->current_row;
	if (window->rows <= shell->cmd_idx)
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
}
