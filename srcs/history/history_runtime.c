/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/04 16:25:34 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** store history to 2D array
** MUST FREE INDIVIDUAL ARRAYS ON EXIT
*/

static void	history_truncate(char **history, char *cmd_line)
{
	int	i;

	i = 0;
	ft_strdel(&history[0]);
	history = (char **)ft_memmove(history, history + 1, sizeof(char *) * 1001);
	while (history[i] != NULL)
		i++;
	history[i] = ft_strdup(cmd_line);
	allocation_check((void *)&history[i]);
	history[++i] = NULL;
}

void	history_runtime(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->history[i] != NULL)
		i++;
	if (i == 100)
		history_truncate(shell->history, shell->cmd_line);
	else
	{
		shell->history[i] = ft_strdup(shell->cmd_line);
		allocation_check((void *)&shell->history[i]);
		shell->hist_idx = i;
	}
}
