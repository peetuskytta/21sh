/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:51 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/15 07:44:43 by pskytta          ###   ########.fr       */
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
	if (i == 3)
	{
		ft_putendl("\nTOO MANY HISTORIES TOO MANY PROBLEMS");
		history_truncate(shell->history, shell->cmd_line);
		i = 0;
		while (shell->history[i] != NULL)
			ft_putendl(shell->history[i++]);
	}
	else
	{
		shell->history[i] = ft_strdup(shell->cmd_line);
		allocation_check((void *)&shell->history[i]);
	}
}
