/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:59:20 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 15:59:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	history_reset(t_shell *shell, t_win *window)
{
	int	i;

	ft_memset(shell->rev_cmd, '\0', sizeof(char) * MAX_BUFF);
	i = 0;
	while (window->row_idx[i] != NULL)
		i++;
	cursor_row_find(shell, window);
	if (window->idx == 0 && window->idx != i)
		window->current_row = window->current_row - i - 1;
	else if (i != window->idx)
		window->current_row = window->current_row - i + 1;
}
