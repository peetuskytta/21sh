/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_listen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:50:05 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/21 14:21:05 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	keys_heredoc(t_shell *shell, char *input, int fd, int *i)
{
	(void)shell;
	if (input[0] == 27)
	{
		while (input[*i] != '\0')
			*i += 1;
		return (1);
	}
	else if (input[0] == ENTER)
	{
		ft_putendl_fd(shell->temp, fd);
		ft_memset(shell->temp, '\0', sizeof(char) * MAX_BUFF + 1);
		return (ENTER);
	}
	else
		return (0);
}

int	heredoc_listen(t_shell *shell, char *input, int fd)
{
	int	i;
	int	key;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == CTRL_D && shell->cmd_idx == 0)
			kill_mode("exit", shell);
		else if (input[i] == CTRL_D && shell->cmd_idx > 0)
			break ;
		key = keys_heredoc(shell, input, fd, &i);
		if (input[i] == ENTER)
		{
			ft_putstr_fd("\n> ", STDOUT_FILENO);
			return (-1);
		}
		else if (shell->cmd_idx + 1 <= MAX_BUFF && key == 0)
		{
			if (input[i] == '\t')
				input[i] = ' ';
			shell->temp[shell->cmd_idx] = input[i];
			shell->cmd_idx++;
			//function to print to a file to save the char similar to this ^^^
			ft_putchar_fd(input[i], fd);
		}
		i++;
	}
	return (1);
}
