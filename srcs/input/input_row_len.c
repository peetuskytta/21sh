/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_row_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:35:22 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/04 13:50:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_row_len(t_shell *shell, t_win *window)
{
	int	x;

	window->rows_q += 1;
	x = window->rows_q;
	if (x > MAX_BUFF)
		ft_perror(QUOTE_TOO_LONG);
	else
		window->row_idx[x] = shell->prmpt_len + shell->cmd_idx;
}