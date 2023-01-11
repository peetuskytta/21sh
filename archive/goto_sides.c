/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/11 17:11:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	ft_finword_rev(char *str)
{
	int	i;

	i = ft_strilen(str) - 1;
	if (i <= 1)
	{
		if (i == -1 || i == 0)
			return (0);
		else
			return (1);
	}
	while (ft_isspace(str[i]) && i > 0)
		i--;
	while (!ft_isspace(str[i]) && i > 0)
		i--;
	if (i == 0 || i == 1)
		return (i);
	return (i + 1);
}

static void	goto_coordinates(t_shell *shell, t_win *window, int key)
{
	if (key == 'l')
	{
		if (window->loc == 0 && window->idx > 0)
		{
			window->loc = window->cols;
			window->current_row--;
			window->idx--;
		}
		else
		{
			if (window->idx == 0 && window->loc <= shell->prmpt_len)
				return ;
			window->loc -= 1;
		}
		cursor_load(shell, window->loc, window->current_row);
	}
	else
	{
		if (window->cols == window->loc && window->row_idx[window->idx + 1])
		{
			window->loc = 0;
			window->current_row += 1;
			window->idx += 1;
		}
		else
		{
			if (window->idx == 0
				&& window->loc > shell->cmd_idx + shell->prmpt_len)
				return ;
			else if (window->idx > 0
				&& window->loc >= ft_strilen(window->row_idx[window->idx]))
				return ;
			window->loc += 1;
		}
		cursor_load(shell, window->loc, window->current_row);
	}
}

int	goto_sides(t_shell *shell, t_win *window, int key)
{
	int	ws;

	if (key == 'l' || key == 'r')
	{
		if (key == 'l')
			chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, 1);
		else
			chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, 1);
		goto_coordinates(shell, window, key);
	}
	else if (key == 98)
	{
		ws = ft_strilen(shell->cmd_line) - ft_finword_rev(shell->cmd_line);
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, ws);
		window->loc = ft_strilen(shell->cmd_line) + shell->prmpt_len + 1;
		goto_word(shell, window, window->loc, 98);
	}
	else if (key == 102)
	{
		ws = ft_strilen(shell->rev_cmd) - ft_finword_rev(shell->rev_cmd);
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, ws);
		goto_word(shell, window, ft_strilen(shell->cmd_line), 102);
	}
	return (1);
}
