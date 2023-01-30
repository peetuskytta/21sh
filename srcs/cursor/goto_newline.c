/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 10:18:56 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_newline(t_shell *shell, t_win *window)
{
	int	i;

	i = ft_strilen(shell->rev_cmd);
	if (i > 0)
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, i);
	i = ft_strilen(shell->q_input);
	if (i + shell->cmd_idx + 1 > MAX_BUFF * 2)
	{
		ft_error_nl(shell, CMD_TOO_LONG);
		return ;
	}
	if (i > 0)
	{
		shell->q_input[i] = '\n';
		i += 1;
	}
	ft_memcpy(&shell->q_input[i], shell->cmd_line, ft_strilen(shell->cmd_line));
	(void)window;
	read_quote(shell);
}
