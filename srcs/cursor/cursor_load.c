/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:49:26 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/06 12:26:28 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cursor_load(t_shell *shell, int x, int y)
{
	if (x >= shell->prmpt_len && x <= shell->cmd_idx + shell->prmpt_len)
		ft_putstr(tgoto(tgetstr("cm", NULL), x, y));
}
