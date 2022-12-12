/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 17:23:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_escape(t_shell *shell, char *input)
{
	if (input[0] == 27 && input[1] == '\0')
	{
		ft_print_fd(STDOUT_FILENO, "ESCAPE\n");
		return (1);
	}
	else
	{
		shell->dir_len = 0;
		return (0);
	}
}

static int is_arrow(t_shell *shell, t_win *window, char *input)
{
	int	i;

	i = 1;
	if (input[1] == 91 && input[2] == 68 && input[3] == 0)
		return (goto_sides(window, 'l'));
	else if (input[1] == 91 && input[2] == 67 && input[3] == 0)
		return (goto_sides(window, 'r'));
	else if (input[1] == 91 && input[2] == 66 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW DOWN\n");
	else if (input[1] == 91 && input[2] == 65 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW UP\n");
	else
		i = 0;
	shell->dir_len = 0;
	return (i);
}

int	special_keys(t_shell *shell, char *input)
{

	if (input[0] == 27 && !is_arrow(shell, &shell->window, input))
		return (is_escape(shell, input));
	else if (input[0] == ENTER)
	{
		goto_newline(shell);
		cmd_line_prompt(shell->quote);
		return (ENTER);
	}
	else
		return (0);
}
