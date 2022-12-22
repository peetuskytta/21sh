/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/22 12:02:30 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

		// tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, stdin_char);
		// tputs(tgetstr("cd", NULL), 1, stdin_char);
		// tputs(tgoto(tgetstr("cm", NULL), 0, 1), 1, stdin_char);
		// tputs(tgetstr("cd", NULL), 1, stdin_char);
void	goto_newline(t_shell *shell, t_win *window)
{
	int	i;

	i = ft_strilen(shell->rev_cmd);
	chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, i);
	shell->cmd_line = ft_strtrim(shell->cmd_line);
	allocation_check((void *)&shell->cmd_line);
	window->rows += 1;
	window->current_row += 1;
	read_quote(shell);
}
