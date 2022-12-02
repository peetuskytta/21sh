/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:01:43 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/02 13:30:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	keypress(t_shell *shell, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == CTRL_D)
			kill_mode("exit", shell);
		else if (input[i] == shell->quote && input[i] != '\0')
		{
			shell->quote = EOF;
			return ;
		}
		else if (input[i] != '\0' && !ft_isprint(input[i]))
		{
			while (input[i] && !ft_isprint(input[i]))
			{
				if (input[i++] == 9)
					write(STDOUT_FILENO, "\t", 1);
				ft_print_fd(STDOUT_FILENO, "%u\n", input[i]);
				i++;
			}
		}
		else if (ft_isprint(input[i]))
		{
			stdin_char(input[i]);
			cmd_line(shell, input[i]);
		}
		i++;
	}
	goto_newline(shell);
}

void	read_key(t_shell *shell, char *input)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		ft_memset(input, 0, sizeof(char) * (MAX_BUFF + 1));
		i = read(STDIN_FILENO, input, MAX_BUFF);
		if (i == -1)
			return ;
		keypress(shell, input);
	}
}

// SIGNAL - together
// READ_INPUT - together
// BUILTINS - together
// HISTORY - together

// TERMCAPS - rori
// KEYPRESS LISTEN - rori
// SPECIAL KEYS - rori
// CURSOR - rori
// COMMAND LINE PARSE - peetu
// PIPES & REDIRECT - peetu
// AGRIGATE - peetu
