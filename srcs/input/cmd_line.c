/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:38 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/14 16:54:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line(t_shell *shell, char c)
{
	int	i;

	i = ft_strilen(shell->cmd_line);
	if (i < shell->cmd_idx)
	{
		shell->cmd_line[i] = c;
		shell->cmd_idx++;
	}
	else
	{
		shell->cmd_line[shell->cmd_idx] = c;
		shell->cmd_idx++;
	}
}
