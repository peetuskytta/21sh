/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/28 16:08:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_word(t_shell *shell, t_win *window, int ws, int key)
{
	int	x;
	int	y;

	y = window->current_row;
	if (key == 98)
	{
		x = shell->cmd_idx - ws + shell->prmpt_len;
		if (x > 4 && x <= shell->cmd_idx)
		{
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
			tputs(tgoto(tgetstr("cd", NULL), x, y), 1, stdin_char);
		}
		else if (x == 4)
			tputs(tgoto(tgetstr("cm", NULL), shell->prmpt_len, y), 1, stdin_char);
	}
	else
	{
		x = ws + shell->prmpt_len;
		if (x <= shell->cmd_idx + shell->prmpt_len)
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
	}
}

// currently clears the words but doesn't re-output them
// some blinky shit happening as Juho said
// what a lil blinky bitch ive made