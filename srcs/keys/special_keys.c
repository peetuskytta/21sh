/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/17 17:06:03 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_escape(t_shell *shell, t_win *win, char *input, int *i)
{
	if (input[0] == 27)
	{
		while (input[*i])
			*i += 1;
		return (1);
	}
	else if (input[0] == 127)
	{
		*i += 2;
		if (ft_strilen(shell->cmd_line) - 1 >= 0
			&& cursor_move(shell, win, 1, 'l') == 1)
		{
			shell->cmd_line[ft_strilen(shell->cmd_line) - 1] = '\0';
			shell->cmd_idx--;
			cursor_row_find(shell, win);
			if (ft_strilen(shell->cmd_line) > 0)
				ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
			if (ft_strilen(shell->rev_cmd) > 0)
				input_rev_cmd(shell);
			cursor_load(win, 0);
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
	if (input[1] == '[' && input[3] == 0 && (input[2] == 'H'
			|| input[2] == 'F'))
	{
		if (input[2] == 'H')
			cursor_goto_end(shell, window, 'H');
		else if (input[2] == 'F')
			cursor_goto_end(shell, window, 'F');
		*i += 4;
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
			&& !(is_home_end(shell, &shell->window, input, i))
			&& !(is_escape(shell, &shell->window, input, i)))
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
