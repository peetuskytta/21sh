/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:50:18 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/29 16:10:05 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	grep_coordinates(t_win *window, char *buf)
{
	int	i;
	int	x;
	int	y;

	i = 2;
	x = 0;
	y = 0;
	if (!ft_strequ("\x1B[6n", buf))
		return ;
	while (buf[i] != ';')
	{
		y = (y * 10) + buf[i] - '0';
		i++;
	}
	while (buf[i] != 'R')
	{
		x = (x * 10) + buf[i] - '0';
		i++;
	}
	window->current_row = y;
	window->loc = x;
}

void	cursor_find(t_win *window)
{
	char	buf[MAX_BUFF + 1];

	ft_putstr_fd("\x1B[6n", STDOUT_FILENO);
	ft_memset(buf, 0, sizeof(char) * (MAX_BUFF + 1));
	if (read(STDOUT_FILENO, &buf, MAX_BUFF) > 0)
		grep_coordinates(window, buf);
	ft_memset(buf, 0, sizeof(char) * (MAX_BUFF + 1));
}