/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/10 17:13:53 by zraunio          ###   ########.fr       */
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
			window->current_row += 1;
			return (1);
		}
	}
	return (0);
}

static void	check_cmd_line_row(t_shell *shell, t_win *window)
{
	int	idx;
	int	loc;

	if (window->cols < shell->cmd_idx + shell->prmpt_len)
	{
		ft_memset(&window->row_idx[1], 0, sizeof(char *) * (MAX_BUFF - 1));
		loc = window->cols - shell->prmpt_len;
		idx = 1;
		while (shell->input[loc] != '\0' && loc <= MAX_BUFF && idx <= MAX_BUFF)
		{
			window->row_idx[idx] = &shell->input[loc];
			loc += window->cols;
			idx++;
		}
		window->idx = idx - 1;
	}
}

static void	reset_input(t_shell *shell)
{
	int	i;

	ft_memset(shell->input, 0, sizeof(char) * (MAX_BUFF + 1));
	i = ft_strilen(shell->cmd_line) - 1;
	if (i > 0)
		shell->input = ft_strcpy(shell->input, shell->cmd_line);
	i = ft_strilen(shell->rev_cmd) - 1;
	if (i > 0)
		chrcpy_str_rev(shell->rev_cmd, &shell->input[i], MAX_BUFF, i);
}

void	cmd_line(t_shell *shell, t_win *window, char c)
{
	int	i;

	i = ft_strilen(shell->cmd_line);
	shell->cmd_line[i] = c;
	shell->cmd_idx++;
	reset_input(shell);
	check_cmd_line_row(shell, window);
	if (check_cursor_loc(window) == 0)
		window->loc += 1;
}
