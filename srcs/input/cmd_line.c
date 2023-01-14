/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 14:42:28 by zraunio          ###   ########.fr       */
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
	ft_print_fd(open("txt.txt", O_WRONLY | O_APPEND), "1.\ncmd: %s\nrev: %s\n",
		shell->cmd_line, shell->rev_cmd);
	cmd_line_check_row(shell, window);
	ft_print_fd(open("txt.txt", O_WRONLY | O_APPEND), "2.\ncmd: %s\nrev: %s\n",
		shell->cmd_line, shell->rev_cmd);
	if (check_cursor_loc(window) == 0)
		window->loc += 1;
}
