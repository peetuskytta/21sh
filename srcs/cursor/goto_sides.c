/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/17 14:57:36 by zraunio          ###   ########.fr       */
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

static void	chrcpy_left_right(char *cmd, char *rev, int max, int n)
{
	int		i;
	int		j;

	i = ft_strlen(cmd) - 1;
	j = ft_strlen(rev);
	if (i < 0 || j >= max)
		return ;
	while (n-- > 0)
	{
		rev[j++] = cmd[i];
		cmd[i--] = '\0';
	}
	rev[j] = '\0';
}

int	goto_sides(t_shell *shell, t_win *window, int key)
{
	int	ws;

	if (key == 'l')
	{
		window->cols--;
		chrcpy_left_right(shell->cmd_line, shell->rev_cmd, MAX_BUFF, 1);
		tputs(tgetstr("le", NULL), 1, stdin_char);
	}
	else if (key == 'r')
	{
		window->cols++;
		chrcpy_left_right(shell->rev_cmd, shell->cmd_line, MAX_BUFF, 1);
		tputs(tgetstr("nd", NULL), 1, stdin_char);
	}
	else if (key == 98)
	{
		ws = ft_finword_rev(shell->cmd_line);
		chrcpy_left_right(shell->cmd_line, shell->rev_cmd, MAX_BUFF, ft_strilen(shell->cmd_line) - ws);
		goto_position(shell, window, ft_strilen(shell->cmd_line) - ws);
	}
	else if (key == 102)
	{
		ws = ft_finword_rev(shell->rev_cmd);
		chrcpy_left_right( shell->rev_cmd, shell->cmd_line, MAX_BUFF, ft_strilen(shell->rev_cmd) - ws);
		goto_position(shell, window, ft_strilen(shell->rev_cmd) - ws);
	}
	return (1);
}
