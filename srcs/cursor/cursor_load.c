/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:26 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/10 17:58:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_shell *shell, int x, int y)
{
	shell->env_iflg = 0;
	ft_putstr(tgoto(tgetstr("cm", NULL), x, y));
}
