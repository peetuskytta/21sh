/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_listen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:50:05 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/21 11:32:29 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	keys_heredoc(t_shell *shell, char *input, int *i)
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
		// check if EOF in input
		// write your own goto_nl
		// goto_newline(shell, &shell->window);
		// ft_memset the input.
		return (ENTER);
	}
	else
		return (0);
}


void	heredoc_listen(t_shell *shell, char *input)
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
		key = keys_heredoc(shell, input, &i);
		if (input[i] == ENTER)
			shell->end = 1;
		else if (shell->cmd_idx + 1 <= MAX_BUFF && key == 0)
		{
			if (input[i] == '\t')
				input[i] = ' ';
			//function to print to a file to save the char.
			stdin_char(input[i]);
		}
		i++;
	}
}