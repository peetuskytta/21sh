/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_row_idx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:01 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/03 17:16:08 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_row_idx(t_win *window)
{
	int	x;

	x = 0;
	while (x <= MAX_BUFF + 1)
		window->row_idx[x++] = -1;
	window->rows_q = 0;
}