/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 15:20:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	check_cursor_loc(t_win *window)
{
	if (window->cols == window->loc)
	{
		if (window->idx > 0)
		{
			window->loc = 1;
			return (1);
		}
	}
	return (0);
}

void	cmd_line(t_shell *shell, t_win *window, char c)
{
	int	i;

	i = ft_strilen(shell->cmd_line);
	shell->cmd_line[i] = c;
	shell->cmd_idx++;
	cmd_line_check_row(shell, window);
	if (check_cursor_loc(window) == 0)
		window->loc += 1;
}
