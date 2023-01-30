/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrlc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:36:30 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 14:43:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	key_is_ctrlc(t_shell *shell, t_win *win)
{
	win->idx = 0;
	ft_memset(win->row_idx, '\0', sizeof(char *) * (MAX_BUFF));
	ft_memset(shell->cmd_line, '\0', sizeof(char) * (MAX_BUFF + 1));
	ft_memset(shell->rev_cmd, '\0', sizeof(char) * (MAX_BUFF + 1));
	win->row_idx[win->idx] = &shell->cmd_line[0];
	ft_memset(shell->temp, '\0', sizeof(char) * (MAX_BUFF + 1));
	ft_memset(shell->q_input, '\0', sizeof(char) * (MAX_BUFF * 2 + 1));
	ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	shell->cmd_idx = 0;
	win->loc = shell->prmpt_len;
	shell->quote = EOF;
	cursor_find(shell, win);
	cursor_load(win, -1);
}
