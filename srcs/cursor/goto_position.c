/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/22 14:17:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_position(t_shell *shell, t_win *window, int ws, int key)
{
	int	x;
	int	y;

	y = window->current_row;
	if (key == 98)
	{
		x = shell->cmd_idx - ws + 3;
		if (x > 4 && x <= shell->cmd_idx)
		{
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
			tputs(tgoto(tgetstr("cd", NULL), x, y), 1, stdin_char);
		}
		else if (x == 4)
			tputs(tgoto(tgetstr("cm", NULL), 3, y), 1, stdin_char);
	}
	else
	{
		x = ws + 3;
		if (x <= shell->cmd_idx + 3)
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
	}
}
