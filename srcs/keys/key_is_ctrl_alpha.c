/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_alpha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:38:49 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/30 15:51:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	key_is_ctrl_alpha(t_shell *shell, t_win *window, char *input, int *i)
{
	if (input[0] == CTRL_W)
	{
		*i += 1;
		shell->env_iflg = 0;
		window->current_row += 0;
		ft_putendl("CPY");
		return (1);
	}
	else if (input[0] == CTRL_R)
	{
		*i += 1;
		shell->env_iflg = 0;
		window->current_row += 0;
		ft_putendl("CUT");
		return (1);
	}
	else if (input[0] == CTRL_P)
	{
		ft_putchar(input[0]);
		*i += 1;
		shell->env_iflg = 0;
		window->current_row += 0;
		ft_putendl("PST");
		return (1);
	}
	else
		return (0);
}