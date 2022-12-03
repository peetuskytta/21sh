/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/03 17:00:42 by zraunio          ###   ########.fr       */
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
		else if (!special_keys(shell,input))
		{
			stdin_char(input[i]);
			cmd_line(shell, input[i]);
		}
		// ft_print_fd(STDOUT_FILENO, "%u\n", input[i++]);
		// else if (input[i] == shell->quote && input[i] != '\0')
		// {
		// 	shell->quote = EOF;
		// 	return ;
		// }
		// else if (input[i] != '\0' && !ft_isprint(input[i]))
		// 	while (input[i] && !ft_isprint(input[i]))
		// 		ft_print_fd(STDOUT_FILENO, "%u\n", input[i++]);
		i++;
	}
	goto_newline(shell);
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
