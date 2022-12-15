/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/13 15:21:59 by zraunio          ###   ########.fr       */
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
		key = special_keys(shell, input, &i);
		if (key == 13)
			shell->end = 1;
		else if (!key)
		{
			if (shell->rev_cmd[0] == '\0')
				stdin_char(input[i]);
			else
				cmd_line_stdin(shell);
		}
		cmd_line(shell, input[i]);
		i++;
	}
}
