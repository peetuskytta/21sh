/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_midline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:05:11 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/18 18:59:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_midline(t_shell *shell, t_win *window)
{
	int	x;
	int	i;
	int	y;

	i = 0;
	while (window->row_idx[i] != NULL)
		i++;
	x = shell->prmpt_len;
	y = window->current_row - 1;
	tputs(tgoto(tgetstr("cm", NULL), x, y), i, stdin_char);
	tputs(tgoto(tgetstr("cd", NULL), x, y), i, stdin_char);
	int	idx;
	int	j;
	int	loc;

	ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	j = ft_strilen(shell->cmd_line) - 1;
	if (j > 0)
		shell->input = ft_strcpy(shell->input, shell->cmd_line);
	j = ft_strilen(shell->rev_cmd) - 1;
	if (j > 0)
		ft_strcpyrev(shell->rev_cmd, &shell->input[j], MAX_BUFF, i);
	if (window->cols < shell->cmd_idx + shell->prmpt_len)
	{
		loc = window->cols - shell->prmpt_len;
		idx = 1;
		while (shell->input[loc] != '\0' && loc <= MAX_BUFF && idx <= MAX_BUFF)
		{
			window->row_idx[idx] = NULL;
			window->row_idx[idx] = &shell->input[loc];
			loc += window->cols;
			idx++;
		}
		window->idx = idx - 1;
	}
	// x = 0;
	// while (window->row_idx[x] != NULL)
	// 	x++;
	// if (x > i)
	// 	window->current_row = window->current_row + (window->idx - x + 1);
	// if (ft_strilen(shell->cmd_line) > 0)
	// 	ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	// if (ft_strilen(shell->rev_cmd) > 0)
	// 	input_rev_cmd(shell);
	// cursor_load(window, 0);
	ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, window->current_row
				+ window->idx - 1));
}