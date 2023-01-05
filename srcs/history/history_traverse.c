/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:29:03 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 15:59:12 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
/*
** delete stdin up to prompt
** go to the idx history item and display it instead
** idx--;
** history item doesn't replace cmd_line
** cmd_line stays in shell for when user goes down
*/

void	history_traverse(t_shell *shell, int *idx, int key)
{
	int	i;

	i = *idx;
	cursor_reset_line(&shell->window, 0);
	cmd_line_prompt(shell->quote);
	if (key == 65 && i >= 0)
	{
		shell->temp = ft_strcpy(shell->temp, shell->cmd_line);
		ft_memset(shell->cmd_line, 0, sizeof(char) * MAX_BUFF);
		shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i]);
		shell->cmd_idx = ft_strilen(shell->cmd_line);
		ft_putstr_fd(shell->history[i], STDIN_FILENO);
		*idx -= 1;
	}
	else if (key == 66)
	{
		*idx += 1;
		i = *idx;
		if (shell->history[i + 1] != NULL)
		{
			ft_memset(shell->cmd_line, 0, sizeof(char) * (MAX_BUFF + 1));
			shell->cmd_line = ft_strcpy(shell->cmd_line, shell->history[i + 1]);
			shell->cmd_idx = ft_strilen(shell->cmd_line);
			ft_putstr_fd(shell->history[i + 1], STDIN_FILENO);
		}
		else
		{
			ft_memset(shell->cmd_line, 0, sizeof(char) * MAX_BUFF);
			shell->cmd_line = ft_strcpy(shell->cmd_line, shell->temp);
			shell->cmd_idx = ft_strilen(shell->cmd_line);
			ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
		}
	}
}
