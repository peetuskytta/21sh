/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/07 15:14:21 by zraunio          ###   ########.fr       */
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
		ft_putstr_fd(window->row_idx[window->idx], STDIN_FILENO);
		stdin_char(c);
		input_rev_cmd(shell);
	}
}
