/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/04 14:00:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_reprint(t_shell *shell, t_win *window, char c)
{
	int	x;

	x = shell->prmpt_len;
	cursor_reset_line(window, x);
	ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	stdin_char(c);
	input_rev_cmd(shell);
	window->loc += 1;
	cursor_load(shell, window->loc, window->current_row);
}
