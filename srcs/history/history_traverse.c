/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:29:03 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/20 09:19:34 by zraunio          ###   ########.fr       */
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
	win->idx = 0;
	win->loc = shell->prmpt_len + shell->cmd_idx;
	ft_memset(&win->row_idx[1], '\0', sizeof(char *) * (MAX_BUFF - 1));
	cmd_line_check_row(shell, win);
	if (ft_strilen(shell->cmd_line) > 0)
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	if (win->row_idx[1] == NULL)
	{
		cursor_find(shell, win);
		win->loc = shell->prmpt_len + shell->cmd_idx;
		cursor_load(win, 0);
	}
	else
	{
		cursor_find(shell, win);
		win->loc = ft_strilen(win->row_idx[win->idx]);
		cursor_load(win, 0);
	}
}

static void	reset_history(t_shell *shell, t_win *window)
{
	int	i;

	ft_memset(shell->rev_cmd, '\0', sizeof(char) * MAX_BUFF);
	i = 0;
	while (window->row_idx[i] != NULL)
		i++;
	cursor_row_find(shell, window);
	if (window->idx == 0 && window->idx != i)
		window->current_row = window->current_row - i - 1;
	else if (i != window->idx)
		window->current_row = window->current_row - i + 1;
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
