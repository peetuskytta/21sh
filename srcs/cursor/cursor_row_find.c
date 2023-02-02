/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_row_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:11 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 14:40:55 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_row_find(t_shell *shell, t_win *win)
{
	int	i;

	i = 0;
	while (win->row_idx[i] != NULL)
		i++;
	if (win->idx == 0)
	{
		if (win->idx != i)
			cursor_reset_line(win, shell->prmpt_len, i);
		else
			cursor_reset_line(win, shell->prmpt_len, -1);
	}
	else
		cursor_reset_line(win, shell->prmpt_len, i);
}
