/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrlc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:36:30 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/23 19:46:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	key_is_ctrlc(t_shell *shell, t_win *win)
{
	ft_memset(shell->cmd_line, '\0', sizeof(char) * MAX_BUFF + 1);
	ft_memset(shell->input, '\0', sizeof(char) * MAX_BUFF + 1);
	ft_memset(shell->rev_cmd, '\0', sizeof(char) * MAX_BUFF + 1);
	ft_memset(shell->q_input, '\0', sizeof(char) * MAX_BUFF + 1);
	ft_memset(win->row_idx, '\0', sizeof(char *) * MAX_BUFF + 1);
	shell->cmd_idx = 0;
	return (ENTER);
}
