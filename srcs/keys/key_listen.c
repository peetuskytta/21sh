/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:35:45 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/15 16:15:09 by zraunio          ###   ########.fr       */
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
		if (input[i] == CTRL_D && shell->cmd_idx == 0)
			kill_mode("exit", shell);
		else if (input[i] == CTRL_D && shell->cmd_idx > 0)
			break ;
		key = special_keys(shell, input, &i);
		if (key == ENTER)
			shell->end = 1;
		else if (key == 0 && shell->cmd_idx <= MAX_BUFF)
		{
			if (input[i] == '\t')
				input[i] = ' ';
			cmd_line(shell, &shell->window, input[i]);
			if (ft_strilen(shell->rev_cmd) > 0)
				cmd_line_reprint(shell, &shell->window);
			else
				stdin_char(input[i]);
		}
		i++;
	}
}
