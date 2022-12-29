/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/29 15:37:36 by zraunio          ###   ########.fr       */
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
		{
			DB;
			kill_mode("exit", shell);
		}
		key = special_keys(shell, input, &i);
		if (key == ENTER)
			shell->end = 1;
		else if (key == 0 && shell->cmd_idx <= MAX_BUFF)
		{
			stdin_char(input[i]);
			cmd_line(shell, input[i]);
		}
		i++;
	}
}
