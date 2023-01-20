/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_goto_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:31:13 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 13:09:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	cursor_go_end(t_shell *shell, t_win *window)
{
	int	len;

	len = ft_strilen(shell->rev_cmd);
	if (len > 0)
	{
		while (window->row_idx[window->idx + 1] != NULL)
			window->idx++;
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, len);
		window->loc = ft_strilen(window->row_idx[window->idx]);
		if (window->idx == 0)
			window->loc += shell->prmpt_len;
	}
}

static void	cursor_go_start(t_shell *shell, t_win *window)
{
	int	len;

	len = ft_strilen(shell->cmd_line);
	if (len > 0)
	{
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, len);
		window->loc = shell->prmpt_len;
		window->idx = 0;
	}
}

void	cursor_goto_end(t_shell *shell, t_win *window, int key)
{
	if (key == 'H')
		cursor_go_start(shell, window);
	else
		cursor_go_end(shell, window);
	cursor_load(window, 0);
}
