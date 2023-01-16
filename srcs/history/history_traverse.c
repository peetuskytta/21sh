/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:29:03 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 23:00:39 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
/*
** delete stdin up to prompt
** go to the idx history item and display it instead
** idx--;
** history item doesn't replace cmd_line
** cmd_line stays in shell for when user goes down
*/

static void	history_cursor(t_shell *shell, t_win *win)
{
	win->loc = shell->prmpt_len + shell->cmd_idx;
	win->idx = 0;
	ft_memset(&win->row_idx[1], '\0', sizeof(char *) * (MAX_BUFF - 1));
	cmd_line_check_row(shell, win);
	if (win->idx > 0)
		win->loc = ft_strilen(win->row_idx[win->idx]);
	cmd_line_reprint(shell, win);
}

static void	reset_history(t_shell *shell, t_win *window)
{
	int	i;

	ft_memset(shell->rev_cmd, '\0', sizeof(char) * MAX_BUFF);
	if (window->idx == 0)
		cursor_reset_line(window, shell->prmpt_len, -1);
	else
	{
		i = 1;
		while (window->row_idx[i] != NULL)
			i++;
		cursor_reset_line(window, shell->prmpt_len, i);
	}
}

static void	history_up(t_shell *shell, t_win *win, int *idx)
{
	int	i;

	reset_history(shell, win);
	i = *idx;
	if (shell->history[i + 1] == NULL)
		shell->temp = ft_strcpy(shell->temp, shell->cmd_line);
	ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
	shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i]);
	shell->cmd_idx = ft_strilen(shell->cmd_line);
	*idx -= 1;
	history_cursor(shell, win);
}

static void	history_down(t_shell *shell, t_win *win, int *idx)
{
	int	i;

	*idx += 1;
	i = *idx;
	if (shell->history[i + 1] != NULL)
	{
		reset_history(shell, win);
		ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i + 1]);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		history_cursor(shell, win);
	}
	else if (shell->temp != NULL)
	{
		reset_history(shell, win);
		ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->temp);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		ft_memset(shell->temp, '\0', sizeof(char) * MAX_BUFF);
		history_cursor(shell, win);
	}
}

void	history_traverse(t_shell *shell, t_win *win, int *idx, int key)
{
	int	i;

	i = *idx;
	if (key == 65 && i >= 0)
		history_up(shell, win, idx);
	else if (key == 66 && shell->history[i + 1] != NULL && shell->temp != NULL)
		history_down(shell, win, idx);
}
