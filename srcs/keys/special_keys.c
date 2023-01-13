/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/13 16:41:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_escape(t_shell *shell, t_win *win, char *input, int *i)
{
	int	flg;

	flg = 0;
	if (win->row_idx[1] != NULL)
		flg = 1;
	if (input[0] == 27 && input[1] == '\0')
	{
		*i += 2;
		return (1);
	}
	else if (input[0] == 127)
	{
		*i += 2;
		if (shell->cmd_idx > 0 && cursor_move(shell, win, 1, 'l') == 1)
		{
			shell->cmd_line[ft_strilen(shell->cmd_line) - 1] = '\0';
			shell->cmd_idx--;
			cmd_line_reprint(shell, win);
			cursor_load(win, win->current_row + win->idx - flg);
		}
		return (1);
	}
	else
		return (0);
}

static int	is_home_end(t_shell *shell, t_win *window, char *input, int *i)
{
	int	len;

	len = shell->cmd_idx;
	(void)window;
	if (input[1] == '[' && input[2] == 'H' && input[3] == 0)
	{
		*i += 4;
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, len);
		// goto_end(shell, window, 'H');
		return (1);
	}
	else if (input[1] == '[' && input[2] == 'F' && input[3] == 0)
	{
		*i += 4;
		// goto_end(shell, window, 'F');
		return (1);
	}
	else
		return (0);
}

int	special_keys(t_shell *shell, char *input, int *i)
{
	if (key_is_ctrl_alpha(shell, &shell->window, input, i) == 1)
		return (1);
	else if (input[0] == ESC || input[0] == 127)
	{
		if (!(key_is_arrow(shell, &shell->window, input, i))
			&& !(is_escape(shell, &shell->window, input, i))
			&& !(is_home_end(shell, &shell->window, input, i)))
			return (0);
		else
			return (1);
	}
	else if (input[0] == ENTER)
	{
		goto_newline(shell, &shell->window);
		return (ENTER);
	}
	else
		return (0);
}
