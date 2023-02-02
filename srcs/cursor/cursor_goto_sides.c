/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_goto_sides.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 14:40:37 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_goto_sides(t_shell *shell, t_win *window, int key)
{
	int	ws;

	(void)window;
	if (key == 'l' || key == 'r')
	{
		if (key == 'l')
			chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, 1);
		else
			chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, 1);
	}
	else if (key == 98)
	{
		ws = ft_strilen(shell->cmd_line) - ft_finword_rev(shell->cmd_line);
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, ws);
	}
	else if (key == 102)
	{
		ws = ft_strilen(shell->rev_cmd) - ft_finword_rev(shell->rev_cmd);
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, ws);
	}
}
