/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/16 15:34:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_escape(t_shell *shell, char *input, int *i)
{
	if (input[0] == 27 && input[1] == '\0')
	{
		*i += 2;
		ft_print_fd(STDOUT_FILENO, "ESCAPE\n");
		return (1);
	}
	else
	{
		(void)shell;
		return (0);
	}
}

static int is_opt_arrow(t_shell *shell, t_win *window, char *input, int *i)
{
	if (input[1] == 'b')
	{
		*i += 6;
		return (goto_sides(shell, window, 98));
	}
	if (input[1] == 'f')
	{
		*i += 6;
		return (goto_sides(shell, window, 102));
	}
	return (0);
}

static int is_arrow(t_shell *shell, t_win *window, char *input, int *i)
{
	ft_putnbr_endl(shell->hist_idx);
	if (input[1] == 91 && input[2] == 68 && input[3] == 0)
	{
		*i += 3;
		return (goto_sides(shell, window, 'l'));
	}
	else if (input[1] == 91 && input[2] == 67 && input[3] == 0)
	{
		*i += 3;
		return (goto_sides(shell, window, 'r'));
	}
	else if (input[1] == 91 && input[2] == 66 && input[3] == 0)
	{
		*i += 3;
		history_traverse(shell, &shell->hist_idx, 66);
		return (1);
	}
	else if (input[1] == 91 && input[2] == 65 && input[3] == 0)
	{
		*i += 3;
		history_traverse(shell, &shell->hist_idx, 65);
		return (1);
	}
	return (0);
}

int	special_keys(t_shell *shell, char *input, int *i)
{
	if (input[0] == ESC)
	{
		if (!(is_arrow(shell, &shell->window, input, i))
			&& !(is_opt_arrow(shell, &shell->window, input, i))
				&& !(is_escape(shell, input, i)))
					return (0);
		else
			return (1);
	}
	else if (input[0] == ENTER)
	{
		//goto_newline(shell);
		cmd_line_prompt(shell->quote);
		return (ENTER);
	}
	else
		return (0);
}
