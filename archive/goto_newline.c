/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:48:04 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/05 17:34:23 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	goto_newline(t_shell *shell, t_win *window)
{
	int	i;

	i = ft_strilen(shell->rev_cmd);
	if (i > 0)
		chrcpy_str_rev(shell->rev_cmd, shell->cmd_line, MAX_BUFF, i);
	window->rows += 1;
	read_quote(shell);
}
