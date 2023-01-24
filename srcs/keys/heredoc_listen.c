/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_listen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:50:05 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/24 15:21:57 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_delim(t_shell *shell)
{
	if (ft_strstr_start(shell->input, shell->delim) != 0)
	{
		// trim the delimiter from input before writing it to fd
		return (1);
	}
	return (0);
}

static int	keys_heredoc(char *input, int *i)
{
	if (input[0] == 27)
	{
		while (input[*i] != '\0')
			*i += 1;
		return (1);
	}
	else if (input[0] == ENTER)
		return (ENTER);
	else
		return (0);
}

static void	save_to_heredoc(t_shell *shell, char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	shell->input[shell->cmd_idx] = c;
	shell->cmd_idx++;
}

int	heredoc_listen(t_shell *shell, char *input)
{
	int	i;
	int	key;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == CTRL_D)
			return (-1);
		key = keys_heredoc(input, &i);
		if (key == ENTER)
		{
			save_to_heredoc(shell, '\n');
			if (is_delim(shell) == 1)
				return (-1);
			ft_putstr_fd("> ", STDOUT_FILENO);
		}
		else if (shell->cmd_idx + 1 < shell->window.cols && key == 0)
		{
			if (input[i] == '\t')
				input[i] = ' ';
			save_to_heredoc(shell, input[i]);
		}
		i++;
	}
	return (1);
}
