/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/12 10:35:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_reprint(t_shell *shell, t_win *window, char c)
{
	int	x;

	x = shell->prmpt_len;
	int	fd;

	fd = open("txt.txt", O_RDWR, O_APPEND);
	if (window->idx == 0)
	{
		ft_putendl_fd("first line", fd);
		cursor_reset_line(window, x);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		stdin_char(c);
		input_rev_cmd(shell);
		cursor_load(shell, window, x);
	}
	else
	{
		ft_putendl_fd("another line", fd);
		cursor_reset_line(window, x);
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		tputs(tgoto(tgetstr("cm", NULL), x, window->current_row - window->idx + 1), 1, stdin_char);
		tputs(tgoto(tgetstr("cd", NULL), x, window->current_row - window->idx + 1), 1, stdin_char);
		//ft_putstr_fd(window->row_idx[window->idx], STDIN_FILENO);
		stdin_char(c);
		input_rev_cmd(shell);
		cursor_load(shell, window, x);
	}
	close(fd);
}
