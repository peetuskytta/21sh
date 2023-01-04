/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_row_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:36:40 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/03 16:54:57 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_row_idx(t_win *window, int len)
{
	int	x;

	x = 0;
	while (window->row_idx[x] != -1)
		x++;
	if (x == MAX_BUFF)
		ft_perror(QUOTE_TOO_LONG);
	else
		window->row_idx[x] = len;
}