/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/22 14:15:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	ft_finword_rev(char *str)
{
	int	i;

	i = ft_strilen(str) - 1;
	if (i == 0 || i == 1)
		return (i);
	while (ft_isspace(str[i]))
	{
		i--;
	}
	while (!ft_isspace(str[i]) && i >= 0)
	{
		i--;
	}
	return (i);
}

int	goto_sides(t_shell *shell, t_win *window, int key)
{
	int	ws;

	if (key == 'l')
	{
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, 1);
		tputs(tgetstr("le", NULL), 1, stdin_char);
	}
	else if (key == 'r')
	{
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, 1);
		tputs(tgetstr("nd", NULL), 1, stdin_char);
	}
	else if (key == 98)
	{
		ws = ft_strilen(shell->cmd_line) - ft_finword_rev(shell->cmd_line);
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, ws);
		goto_position(shell, window, ft_strilen(shell->rev_cmd) - 1, 98);
	}
	else if (key == 102)
	{
		ws = ft_strilen(shell->rev_cmd) - ft_finword_rev(shell->rev_cmd);
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, ws);
		goto_position(shell, window, ft_strilen(shell->cmd_line), 102);
	}
	return (1);
}
