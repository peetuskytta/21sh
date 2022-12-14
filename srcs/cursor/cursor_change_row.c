/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_change_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:51:41 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 16:09:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_change_row(t_shell *shell, t_win *window, int key)
{
	int	x;

	x = window->rows_q;
	if (key == 'A' && x >= 0)
	{
		if (x - 1 < 0)
			return ;
		window->current_row -= 1;
		window->rows_q -= 1;
		cursor_load(shell, shell->prmpt_len, window->current_row);
	}
	else if (key == 'B' && window->row_idx[x + 1] != -1)
	{
		window->current_row += 1;
		window->rows_q += 1;
		cursor_load(shell, shell->prmpt_len, window->current_row);
	}
}