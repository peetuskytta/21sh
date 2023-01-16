/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:29:03 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 15:58:04 by zraunio          ###   ########.fr       */
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

static void	reset_history(t_shell *shell, t_win *window)
{
	int	i;

	if (window->idx == 0)
		cursor_reset_line(window, shell->prmpt_len, -1);
	else
	{
		i = 1;
		while (window->row_idx[i + 1] != NULL)
			i++;
		cursor_reset_line(window, shell->prmpt_len, i);
	}
}

static void	history_up(t_shell *shell, t_win *win, int *idx)
{
	int	i;

	i = *idx;
	if (shell->history[i + 1] == NULL)
		shell->temp = ft_strcpy(shell->temp, shell->cmd_line);
	ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
	shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i]);
	shell->cmd_idx = ft_strilen(shell->cmd_line);
	win->loc = shell->cmd_idx + shell->prmpt_len;
	cmd_line_check_row(shell, win);
	reset_history(shell, win);
	ft_putstr_fd(shell->history[i], STDIN_FILENO);
	*idx -= 1;
}

static void	history_down(t_shell *shell, t_win *win, int *idx)
{
	int	i;

	*idx += 1;
	i = *idx;
	if (shell->history[i + 1] != NULL)
	{
		ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i + 1]);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		win->loc = shell->cmd_idx + shell->prmpt_len;
		cmd_line_check_row(shell, win);
		reset_history(shell, win);
		ft_putstr_fd(shell->history[i + 1], STDIN_FILENO);
	}
	else if (shell->temp != NULL)
	{
		ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->temp);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		win->loc = shell->cmd_idx + shell->prmpt_len;
		cmd_line_check_row(shell, win);
		reset_history(shell, win);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		ft_memset(shell->temp, '\0', sizeof(char) * MAX_BUFF);
	}
}

void	history_traverse(t_shell *shell, t_win *win, int *idx, int key)
{
	int	i;

	i = *idx;
	ft_memset(shell->rev_cmd, '\0', sizeof(char) * MAX_BUFF + 1);
	if (key == 65 && i >= 0)
		history_up(shell, win, idx);
	else if (key == 66 && shell->history[i + 1] != NULL && shell->temp != NULL)
		history_down(shell, win, idx);
	cursor_load(win, win->idx);
}
