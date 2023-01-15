/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:42 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/15 11:06:07 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_win *window, int flg)
{
	if (flg == -1)
		ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, window->current_row
				- 1));
	else
	{
		while (window->row_idx[flg] != NULL)
			flg++;
		ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, window->current_row
				+ window->idx - flg));
	}
}
