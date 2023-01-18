/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:36:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/18 15:46:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_reprint(t_shell *shell, t_win *window)
{
	int	x;

	x = shell->prmpt_len;
	cursor_row_find(shell, window);
	if (ft_strilen(shell->cmd_line) > 0)
		ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	if (ft_strilen(shell->rev_cmd) > 0)
		input_rev_cmd(shell);
	cursor_load(window, 0);
}
/*
*/
