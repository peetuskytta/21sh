/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/06 14:21:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

// static void	check_cmd_line_row(t_shell *shell, t_win *window)
// {
// 	int	idx;
// 	int	loc;

// 	if (window->cols < shell->cmd_idx + shell->prmpt_len)
// 	{
// 		loc = window->cols + 1;
// 		idx = 1;
// 		while (shell->cmd_line[loc] != '\0' && loc <= MAX_BUFF)
// 		{
// 			window->row_idx[idx] = &shell->cmd_line[loc];
// 			loc += window->cols;
// 		}
// 	}
// }

// static void	reset_input(t_shell *shell)
// {
// 	int	i;

// 	i = ft_strilen(shell->cmd_line) - 1;
// 	if (i > 0)
// 		shell->input = ft_strcpy(shell->input, shell->cmd_line);
// 	i = ft_strilen(shell->rev_cmd) - 1;
// 	if (i > 0)
// 		chrcpy_str_rev(shell->rev_cmd, &shell->input[i], MAX_BUFF, i);
// 	NL;
// 	ft_putendl(shell->input);
// }

void	cmd_line(t_shell *shell, t_win *window, char c)
{
	int	i;

	i = ft_strilen(shell->cmd_line);
	shell->cmd_line[i] = c;
	shell->cmd_idx++;
	window->loc += 1;
	// reset_input(shell);
	// check_cmd_line_row(shell, window);
}
