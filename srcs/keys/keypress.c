/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/04 11:45:12 by zraunio          ###   ########.fr       */
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
		else if (input[i] == 13)
			goto_newline(shell);
		i++;
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
