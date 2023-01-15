/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:29:03 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/15 14:36:30 by zraunio          ###   ########.fr       */
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

static void	history_up(t_shell *shell, int *idx)
{
	int	i;

	i = *idx;
	cursor_reset_line(&shell->window, shell->prmpt_len, -1);
	cmd_line_prompt(shell->quote);
	if (shell->history[i + 1] == NULL)
		shell->temp = ft_strcpy(shell->temp, shell->cmd_line);
	ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
	shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i]);
	shell->cmd_idx = ft_strilen(shell->cmd_line);
	ft_putstr_fd(shell->history[i], STDIN_FILENO);
	*idx -= 1;
}

static void	history_down(t_shell *shell, int *idx)
{
	int	i;

	*idx += 1;
	i = *idx;
	cursor_reset_line(&shell->window, shell->prmpt_len, -1);
	cmd_line_prompt(shell->quote);
	if (shell->history[i + 1] != NULL)
	{
		ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i + 1]);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		ft_putstr_fd(shell->history[i + 1], STDIN_FILENO);
	}
	else if (shell->temp != NULL)
	{
		ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->temp);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		ft_memset(shell->temp, '\0', sizeof(char) * MAX_BUFF);
	}
}

void	history_traverse(t_shell *shell, t_win *win, int *idx, int key)
{
	int	i;
	int	flg;

	i = *idx;
	flg = -1;
	ft_memset(shell->rev_cmd, '\0', sizeof(char) * MAX_BUFF + 1);
	if (key == 65 && i >= 0)
		history_up(shell, idx);
	else if (key == 66 && shell->history[i + 1] != NULL && shell->temp != NULL)
		history_down(shell, idx);
	cmd_line_check_row(shell, win);
	if (win->idx > 0)
	{
		flg = 0;
		win->loc = ft_strilen(win->row_idx[win->idx]);
	}
	else
		win->loc = shell->cmd_idx + shell->prmpt_len;
	cursor_load(win, flg);
}
