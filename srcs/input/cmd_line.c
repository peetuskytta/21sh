/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:32:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/06 11:35:07 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line(t_shell *shell, char c)
{
	int	i;

	i = ft_strilen(shell->cmd_line);
	// if (i < shell->cmd_idx)
	// {
		shell->cmd_line[i] = c;
		shell->cmd_idx++;
		shell->window.loc += 1;
	// }
	// else
	// {
	// 	shell->cmd_line[shell->cmd_idx] = c;
	// 	shell->cmd_idx++;
	// 	shell->window.loc += 1;
	// }
}
