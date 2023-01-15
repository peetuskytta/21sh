/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/15 14:16:12 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_reprint(t_shell *shell, t_win *window)
{
	int	x;
	int	i;

	x = shell->prmpt_len;
	if (window->idx == 0)
		cursor_reset_line(window, x, -1);
	else
	{
		i = 0;
		while (window->row_idx[i] != NULL)
			i++;
		cursor_reset_line(window, x, i);
	}
	ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	input_rev_cmd(shell);
	cursor_load(window, 0);
}
/*
*/
