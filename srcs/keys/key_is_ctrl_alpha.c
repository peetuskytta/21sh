/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_alpha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:38:49 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/15 16:17:34 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	ctrl_paste(t_shell *shell, t_win *window)
{
	int	len;

	len = ft_strilen(shell->clipbrd);
	if (len > 0)
	{
		ft_putstr_fd(shell->clipbrd, STDIN_FILENO);
		shell->cmd_idx += len;
		ft_memcpy(&shell->cmd_line[ft_strilen(shell->cmd_line)],
			shell->clipbrd, len);
		cursor_move(shell, window, len, 'r');
		cmd_line_check_row(shell, window);
		if (window->row_idx[1] == NULL)
			cursor_load(window, -1);
		else
			cursor_load(window, 0);
	}
}

static void	ctrl_cut(t_shell *shell, t_win *window)
{
	int	i;

	shell->cmd_idx -= ft_strilen(shell->rev_cmd);
	ft_memset(shell->rev_cmd, '\0', sizeof(char) * (MAX_BUFF + 1));
	if (window->row_idx[1] == NULL)
		cursor_reset_line(window, window->loc, -1);
	else
	{
		i = 0;
		while (window->row_idx[i] != NULL)
			i++;
		cursor_reset_line(window, window->loc, i);
	}
}

int	key_is_ctrl_alpha(t_shell *shell, t_win *window, char *input, int *i)
{
	int	len;

	if (input[0] == CTRL_W || input[0] == CTRL_V)
	{
		len = ft_strilen(shell->rev_cmd);
		if (len > 0)
		{
			ft_memset(shell->clipbrd, '\0', sizeof(char) * (MAX_BUFF + 1));
			ft_strcpyrev(shell->rev_cmd, shell->clipbrd, MAX_BUFF, len);
		}
		if (input[0] == CTRL_W)
			ctrl_cut(shell, window);
		*i += 1;
		return (1);
	}
	else if (input[0] == CTRL_P)
	{
		*i += 1;
		ctrl_paste(shell, window);
		return (1);
	}
	else
		return (0);
}
