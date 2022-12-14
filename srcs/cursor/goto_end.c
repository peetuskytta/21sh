/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:31:13 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/30 15:56:40 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_end(t_shell *shell, t_win *window, int key)
{
	int	y;
	int	x;

	y = window->current_row;
	if (key == 'H')
	{
		x = shell->prmpt_len;
		window->loc = x;
		cursor_reset_line(window, x);
		input_rev_cmd(shell);
		cursor_load(shell, x, y);
	}
	else
	{
		x = shell->cmd_idx + shell->prmpt_len;
		window->loc = x;
		cursor_load(shell, x, y);
	}
}
