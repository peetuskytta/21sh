/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_midline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:05:11 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/19 15:29:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_midline(t_shell *shell, t_win *window)
{
	int	i;
	int	flg;

	i = window->idx;
	flg = 1;
	// cursor_row_find(shell, window);
	tputs(tgoto(tgetstr("cm", NULL), shell->prmpt_len, window->current_row - 1), 1, stdin_char);
	tputs(tgoto(tgetstr("cm", NULL), shell->prmpt_len, window->current_row - 1), 1, stdin_char);
	cmd_line_check_row(shell, window);
	if (i < window->idx)
		flg++;
	if (ft_strilen(shell->cmd_line) > 0)
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	if (ft_strilen(shell->rev_cmd) > 0)
		input_rev_cmd(shell);
	ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, window->current_row
				+ window->idx - flg));
}