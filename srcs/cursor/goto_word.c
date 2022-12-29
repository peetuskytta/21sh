/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/29 16:21:47 by zraunio          ###   ########.fr       */
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
		window->loc = x;
		if (x - 1 > shell->prmpt_len)
		{
			tputs(tgoto(tgetstr("cm", NULL), x - 1, y), 1, stdin_char);
			tputs(tgoto(tgetstr("cd", NULL), x - 1, y), 1, stdin_char);
			input_rev_cmd(shell);
			cursor_load(shell, x, y);
		}
		else if (x == shell->prmpt_len + 1)
			cursor_load(shell, shell->prmpt_len, y);
	}
	else
	{
		x = ws + shell->prmpt_len;
		window->loc = x;
		if (x <= shell->cmd_idx + shell->prmpt_len)
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
	}
}
// some blinky shit happening as Juho said
// what a lil blinky bitch ive made