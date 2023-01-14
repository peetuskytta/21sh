/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:57:40 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 14:50:51 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	reset_input(t_shell *shell)
{
	int	i;

	ft_memset(shell->input, 0, sizeof(char) * (MAX_BUFF + 1));
	i = ft_strilen(shell->cmd_line) - 1;
	if (i > 0)
		shell->input = ft_strcpy(shell->input, shell->cmd_line);
	i = ft_strilen(shell->rev_cmd) - 1;
	if (i > 0)
		ft_strcpyrev(shell->rev_cmd, &shell->input[i], MAX_BUFF, i);
}

void	cmd_line_check_row(t_shell *shell, t_win *window)
{
	int	idx;
	int	loc;

	reset_input(shell);
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
}
