/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/30 15:09:23 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_newline(t_shell *shell, t_win *window)
{
	int	i;

	i = ft_strilen(shell->rev_cmd);
	chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, i);
	window->rows += 1;
	window->current_row += 1;
	read_quote(shell);
	cursor_find(window);
	if (window->loc < 3 || window->loc > 9)
		window->loc = shell->prmpt_len;
	ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, window->current_row - 1));
}
