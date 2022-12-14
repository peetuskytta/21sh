/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:10:51 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/14 15:47:56 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** store history to 2D array
** MUST FREE INDIVIDUAL ARRAYS ON EXIT
*/

static void	history_truncate(void ***history)
{
	void	*temp;

	temp = ft_memmove(temp, history, 1000);
}

void	history_runtime(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->history[i] != NULL)
		i++;
	if (i == 3)
		ft_putendl("TOO MANY HISTORIES TOO MANY PROBLEMS");
	else
	{
		shell->history[i] = ft_strdup(shell->cmd_line);
		allocation_check((void *)&shell->history[i]);
	}
}
