/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:26 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 13:15:25 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	move_cursor_right(t_shell *shell, t_win *win, int len)
{
	int	max;

	len = win->loc + len;
	if (win->idx == 0 && win->row_idx[win->idx + 1] == NULL)
		max = shell->prmpt_len + shell->cmd_idx;
	else if (win->idx > 0 && win->row_idx[win->idx + 1] == NULL)
		max = ft_strilen(win->row_idx[win->idx]);
	else
		max = win->cols;
	if (win->loc == max && win->row_idx[win->idx + 1] == NULL)
		return (0);
	if (len > max && win->row_idx[win->idx + 1] != NULL)
	{
		win->loc = len - win->cols;
		win->idx += 1;
	}
	else
		win->loc = len;
	return (1);
}

static int	move_cursor_left(t_shell *shell, t_win *win, int len)
{
	int	min;

	if (win->loc == shell->prmpt_len && win->idx == 0)
		return (0);
	len = win->loc - len;
	if (win->idx == 0 || (len < 0 && win->idx - 1 == 0))
		min = shell->prmpt_len;
	else
		min = 1;
	if ((len < 0 && win->idx - 1 == 0) || (len < min && win->idx > 0))
	{
		win->loc = win->cols + len;
		win->idx -= 1;
	}
	else
		win->loc = len;
	return (1);
}

int	cursor_move(t_shell *shell, t_win *win, int len, int key)
{
	if (key == 'l')
		return (move_cursor_left(shell, win, len));
	else if (key == 'r')
		return (move_cursor_right(shell, win, len));
	else
		return (0);
}
