/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 14:03:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	key_listen(t_shell *shell, char *input)
{
	int	i;
	int	key;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == CTRL_D)
			kill_mode("exit", shell);
		key = special_keys(shell, input);
		if (key == 13)
			shell->end = 1;
		else if (!key)
		{
			stdin_char(input[i]);
			cmd_line(shell, input[i]);
		}
		i++;
	}
}

// SIGNAL - together
// READ_INPUT - together
// BUILTINS - together
// HISTORY - together
// QUOTES - together but peetu is a hero

// KEYPRESS LISTEN - rori
// SPECIAL KEYS - rori
// CURSOR - rori
// COMMAND LINE PARSE - peetu
// PIPES & REDIRECT - peetu
// AGRIGATE - peetu
