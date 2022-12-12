/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:00 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 17:24:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	goto_sides(t_win *window, int key)
{
	if (key == 'l')
	{
		window->cols--;
		tputs(tgoto(tgetstr("le", NULL), 0, 1), 1, stdin_char);
	}
	else
	{
		window->cols++;
		tputs(tgoto(tgetstr("nd", NULL), 0, 1), 1, stdin_char);
	}
	return (1);
}
