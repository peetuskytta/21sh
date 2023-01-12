/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:42 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/12 14:52:11 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_shell *shell, t_win *window)
{
	(void)shell;
	ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, window->current_row));
}