/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:26 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/06 11:36:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_shell *shell, int x, int y)
{
	int	row_idx[4096];
	int	row;

	row = 0;
	while (shell->window.row_idx[row++] != -1)
		row_idx[row] = shell->window.row_idx[row];
	row = shell->window.rows_q;
	if (x >= shell->prmpt_len && x <= row_idx[row])
		ft_putstr(tgoto(tgetstr("cm", NULL), x, y));
}
