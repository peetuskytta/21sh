/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/14 17:57:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	chrcpy_right_left(char *cmd, char *rev, int max, int n)
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
		chrcpy_right_left(shell->cmd_line, shell->rev_cmd, MAX_BUFF, 1);
		//tputs(tgoto(tgetstr("le", NULL), 0, 1), 1, stdin_char);
	}
	else if (key == 'r')
	{
		window->cols++;
		tputs(tgoto(tgetstr("nd", NULL), 0, 1), 1, stdin_char);
	}
	else if (key == 98)
	{
		ws = ft_strchr_index(shell->cmd_line, ' ', 'e');
		chrcpy_right_left(shell->cmd_line, shell->rev_cmd, MAX_BUFF, ft_strilen(shell->cmd_line) - ws);
	}
	return (1);
}
