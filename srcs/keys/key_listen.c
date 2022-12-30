/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/30 16:18:40 by zraunio          ###   ########.fr       */
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
		if (key == ENTER)
			shell->end = 1;
		else if (key == 0 && shell->cmd_idx <= MAX_BUFF)
		{
			if (shell->window.loc <= shell->cmd_idx + shell->prmpt_len)
				cmd_line_reprint(shell, &shell->window, input[i]);
			else
				stdin_char(input[i]);
			cmd_line(shell, input[i]);
		}
		i++;
	}
}
