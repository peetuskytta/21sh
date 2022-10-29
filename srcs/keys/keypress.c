/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/29 15:04:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inlcudes/shell.h"

static char	read_key(void)
{
	int		i;
	char	c;

	i = read(STDIN_FILENO, &c, 1);
	while (i != 1)
	{
		if (i == -1)
			kill_mode("read");
		i = read(STDIN_FILENO, &c, 1);
	}
	return (c);
}

void	keypress(void)
{
	char	c;

	c = read_key();
	while (c)
	{
		if (c == CTRL_C)
			kill_mode("exit");
		else if (ft_iscntrl(c) == 0)
			write(1, &c, 1);
		c = read_key();
	}
}
