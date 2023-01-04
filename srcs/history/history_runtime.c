/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:51 by zraunio           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/03 17:04:10 by pskytta          ###   ########.fr       */
=======
/*   Updated: 2022/12/30 16:22:33 by zraunio          ###   ########.fr       */
>>>>>>> cursor
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
<<<<<<< HEAD
	if (i == 100)
	{
		//ft_putendl("TOO MANY HISTORIES TOO MANY PROBLEMS");
=======
	if (i == 10)
>>>>>>> cursor
		history_truncate(shell->history, shell->cmd_line);
	else
	{
		shell->history[i] = ft_strdup(shell->cmd_line);
		allocation_check((void *)&shell->history[i]);
		shell->hist_idx = i;
	}
}
