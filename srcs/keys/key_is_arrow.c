/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:40:44 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/15 13:46:47 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_opt_updwn(t_shell *shell, t_win *win, char *input, int *i)
{
	int	len;

	len = win->cols;
	if (input[1] == '[' && input[2] == '1' && input[3] == ';'
		&& input[4] == '3' && input[6] == 0 && (input[5] == 'A'
			|| input[5] == 'B'))
	{
		if (input[5] == 'A' && cursor_move(shell, win, len, 'l') == 1)
			chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, len);
		else if (input[5] == 'B' && cursor_move(shell, win, len, 'r') == 1)
			chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, len);
		*i += 7;
		cursor_load(win, 0);
		return (1);
	}
	return (0);
}

static int	is_opt_arrow(t_shell *shell, t_win *win, char *input, int *i)
{
	int	ws;

	if ((input[1] == 'b' || input[1] == 'f') && input[6] == '\0')
	{
		if (input[1] == 'b')
		{
			ws = ft_strilen(shell->cmd_line) - ft_finword_rev(shell->cmd_line);
			if (cursor_move(shell, win, ws, 'l') == 1)
				chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, ws);
		}
		else
		{
			ws = ft_strilen(shell->rev_cmd) - ft_finword_rev(shell->rev_cmd);
			if (cursor_move(shell, win, ws, 'r') == 1)
				chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, ws);
		}
		cursor_load(win, 0);
		*i += 6;
		return (1);
	}
	return (0);
}

static int	is_arrow_updwn(t_shell *shell, t_win *window, char *input, int *i)
{
	if (input[1] == 91 && input[2] == 66 && input[3] == 0)
	{
		*i += 3;
		history_traverse(shell, window, &shell->hist_idx, 66);
		return (1);
	}
	else if (input[1] == 91 && input[2] == 65 && input[3] == 0)
	{
		*i += 3;
		history_traverse(shell, window, &shell->hist_idx, 65);
		return (1);
	}
	return (0);
}

static int	is_arrow_side(t_shell *shell, t_win *window, char *input, int *i)
{
	if (input[1] == 91 && input[3] == 0 && (input[2] == 67 || input[2] == 68))
	{
		if (input[2] == 68)
		{
			if (cursor_move(shell, window, 1, 'l') == 1)
				cursor_goto_sides(shell, window, 'l');
		}
		else
		{
			if (cursor_move(shell, window, 1, 'r') == 1)
				cursor_goto_sides(shell, window, 'r');
		}
		cursor_load(window, 0);
		*i += 3;
		return (1);
	}
	return (0);
}

int	key_is_arrow(t_shell *shell, t_win *window, char *input, int *i)
{
	if (!(is_arrow_side(shell, window, input, i))
		&& !(is_arrow_updwn(shell, window, input, i))
		&& !(is_opt_arrow(shell, window, input, i))
		&& !(is_opt_updwn(shell, window, input, i)))
		return (0);
	else
		return (1);
}
