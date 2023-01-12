/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:26 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/12 10:32:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_shell *shell, t_win *win, int len)
{
	(void)shell;
	ft_putstr(tgoto(tgetstr("cm", NULL), len, win->current_row));
}
