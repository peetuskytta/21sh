/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:43:42 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 13:33:03 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_win *window, int y)
{
	ft_putstr(tgoto(tgetstr("cm", NULL), window->loc, y - 1));
}
