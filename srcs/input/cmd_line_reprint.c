/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/06 17:20:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_reprint(t_shell *shell, t_win *window, char c)
{
	int	x;

	if (window->idx == 0)
	{
		x = shell->prmpt_len;
		cursor_reset_line(window, x);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		stdin_char(c);
		input_rev_cmd(shell);
	}
	else
	{
		x = 0;
		cursor_reset_line(window, x);
		ft_putstr(window->row_idx[window->idx]);
		ft_putchar_fd('\n', open("txt.txt", O_WRONLY | O_APPEND));
		ft_putstr_fd(window->row_idx[window->idx], open("txt.txt", O_WRONLY | O_APPEND));
	}
	cursor_load(shell, window->loc, window->current_row);
}
