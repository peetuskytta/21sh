/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/13 14:18:32 by zraunio          ###   ########.fr       */
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
	if (key == 'l')
	{
		window->cols--;
		chrcpy_right_left(shell->cmd_line, shell->rev_cmd, 1, 1);
		tputs(tgoto(tgetstr("le", NULL), 0, 1), 1, stdin_char);
	}
	else
	{
		window->cols++;
		tputs(tgoto(tgetstr("nd", NULL), 0, 1), 1, stdin_char);
	}
	return (1);
}
