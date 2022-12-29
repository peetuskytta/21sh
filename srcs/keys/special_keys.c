/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/29 10:57:12 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_escape(t_shell *shell, char *input, int *i)
{
	int	row;
	int	pos;

	row = shell->window.current_row;
	if (input[0] == 27 && input[1] == '\0')
	{
		*i += 2;
		ft_print_fd(STDOUT_FILENO, "ESCAPE\n");
		return (1);
	}
	else if (input[0] == 127)
	{
		*i += 2;
		if (shell->cmd_idx > 0)
		{
			shell->cmd_line[shell->cmd_idx] = 0;
			shell->cmd_idx--;
			pos = shell->cmd_idx + shell->prmpt_len;
			tputs(tgoto(tgetstr("cm", NULL), pos, row), row, stdin_char);
			tputs(tgetstr("dc", NULL), row, stdin_char);
		}
		return (1);
	}
	else
		return (0);
}

static int is_home_end(t_shell *shell, t_win *window, char *input, int *i)
{
	if (input[1] == '[' && input[2] == 'H' && input[3] == 0)
	{
		*i += 4;
		chrcpy_str_rev(shell->cmd_line, shell->rev_cmd, MAX_BUFF, shell->cmd_idx);
		goto_end(shell, window, 'H');
		return (1);
	}
	else if (input[1] == '[' && input[2] == 'F' && input[3] == 0)
	{
		*i += 4;
		goto_end(shell, window, 'F');
		return (1);
	}
	else
		return (0);
}

static int	is_opt_arrow(t_shell *shell, t_win *window, char *input, int *i)
{
	if (input[1] == 'b')
	{
		*i += 6;
		return (goto_sides(shell, window, 98));
	}
	else if (input[1] == 'f')
	{
		*i += 6;
		return (goto_sides(shell, window, 102));
	}
	else if (input[1] == '[' && input[2] == '1' && input[3] == ';' 
			&& input[4] == '3' && input[5] == 'A' && input[6] == 0)
	{
		*i += 7;
		ft_putendl(OPTN_UP);
		return (1);
	}
	else if (input[1] == '[' && input[2] == '1' && input[3] == ';' 
			&& input[4] == '3' && input[5] == 'B' && input[6] == 0)
	{
		*i += 7;
		ft_putendl(OPTN_DOWN);
		return (1);
	}
	else
		return (0);
}

static int	is_arrow(t_shell *shell, t_win *window, char *input, int *i)
{
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
	if (key_is_ctrl_alpha(shell, &shell->window, input, i) == 1)
		return (1);
	else if (input[0] == ESC || input[0] == 127)
		{
		if (!(is_arrow(shell, &shell->window, input, i))
			&& !(is_opt_arrow(shell, &shell->window, input, i))
			&& !(is_escape(shell, input, i)) 
			&& !(is_home_end(shell, &shell->window, input, i)))
			return (0);
		else
			return (1);
		}
	else if (input[0] == ENTER)
	{
		goto_newline(shell, &shell->window);
		return (ENTER);
	}
	else
		return (0);
}
