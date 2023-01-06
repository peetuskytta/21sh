/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_row_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:35:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 16:49:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_row_len(t_shell *shell, t_win *window)
{
	int		x;
	int		len;
	char	*temp;

	window->rows_q += 1;
	x = window->rows_q;
	if (x > MAX_BUFF)
		ft_perror(QUOTE_TOO_LONG);
	else
	{
		//first row uses cmd_idx rest uses last newline char strilen
		if (x == 0)
		{
			temp = ft_strrchr(shell->cmd_line, '\n') + 1;
			len = ft_strilen(temp);
		}
		else
			len = shell->cmd_idx;
		window->row_idx[x] = shell->prmpt_len + len;
	}
}