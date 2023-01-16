/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 15:28:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_newline(t_shell *shell, t_win *window)
{
	int	i;

	i = ft_strilen(shell->rev_cmd);
	if (i > 0)
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, i);
	window->rows += 1;
	i = ft_strilen(shell->q_input);
	if (i > 0)
	{
		shell->q_input[i] = '\n';
		i += 1;
	}
	ft_memcpy(&shell->q_input[i], shell->cmd_line, ft_strilen(shell->cmd_line));
	read_quote(shell);
}
