/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/13 16:37:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_reprint(t_shell *shell, t_win *window)
{
	int	x;
	int	flg;

	flg = 0;
	if (window->row_idx[1] != NULL)
		flg = 1;
	x = shell->prmpt_len;
	if (window->idx == 0)
	{
		cursor_reset_line(window, x);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		input_rev_cmd(shell);
	}
	else
	{
		cursor_reset_line(window, x);
		tputs(tgoto(tgetstr("cm", NULL), x, window->current_row - window->idx
				+ 1), 1, stdin_char);
		tputs(tgoto(tgetstr("cd", NULL), x, window->current_row - window->idx
				+ 1), 1, stdin_char);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		input_rev_cmd(shell);
	}
	cursor_load(window, window->current_row - flg);
}
