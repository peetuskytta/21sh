/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:31:13 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/29 16:16:20 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_end(t_shell *shell, t_win *window, int key)
{
	int	y;
	int	x;

	y = window->current_row;
	if (key == 'H')
	{
		x = shell->prmpt_len;
		window->loc = x;
		tputs(tgoto(tgetstr("cm", NULL), x, y), 1, stdin_char);
		tputs(tgoto(tgetstr("cd", NULL), x, y), 1, stdin_char);
		input_rev_cmd(shell);
		cursor_load(shell, x, y);
	}
	else
	{
		x = shell->cmd_idx + shell->prmpt_len;
		window->loc = x;
		cursor_load(shell, x, y);
	}
}