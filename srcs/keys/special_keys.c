/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/16 14:30:01 by pskytta          ###   ########.fr       */
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
		ft_putnbr_endl(shell->env_nbr);
		return (0);
	}
}

static int is_arrow(t_shell *shell, t_win *window, char *input, int *j)
{
	int	i;

	i = 1;
	if (input[1] == 91 && input[2] == 68 && input[3] == 0)
	{
		*j += 3;
		return (goto_sides(shell, window, 'l'));
	}
	else if (input[1] == 91 && input[2] == 67 && input[3] == 0)
	{
		*j += 3;
		return (goto_sides(shell, window, 'r'));
	}
	else if (input[1] == 91 && input[2] == 66 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW DOWN\n");
	else if (input[1] == 91 && input[2] == 65 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW UP\n");
	else
		i = 0;
	return (i);
}

int	special_keys(t_shell *shell, char *input, int *i)
{

	if (input[0] == 27 && !is_arrow(shell, &shell->window, input, i))
		return (is_escape(shell, input, i));
	else if (input[0] == ENTER)
	{
		goto_newline(shell);
	//	cmd_line_prompt(shell->quote);
		return (ENTER);
	}
	else
		return (0);
}
