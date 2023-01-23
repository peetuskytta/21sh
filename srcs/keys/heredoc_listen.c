/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_listen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:50:05 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/23 19:29:45 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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

static void	save_to_heredoc(int fd, char input)
{
	ft_putchar_fd(input, STDOUT_FILENO);
	ft_putchar_fd(input, fd);
}

int	heredoc_listen(t_shell *shell, char *input, int fd)
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
			save_to_heredoc(fd, '\n');
			ft_putstr_fd("> ", STDOUT_FILENO);
		}
		else if (shell->cmd_idx + 1 < shell->window.cols && key == 0)
		{
			if (input[i] == '\t')
				input[i] = ' ';
			shell->cmd_idx++;
			save_to_heredoc(fd, input[i]);
		}
		i++;
	}
	return (1);
}
