/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:41:11 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/13 15:26:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	cmd_line_stdin(t_shell *shell)
{
	int	i;

	NL;
	ft_putstr_fd(shell->cmd_line, STDIN_FILENO);
	i = ft_strilen(shell->rev_cmd);
	while (i--)
		ft_putchar_fd(shell->rev_cmd[i], STDIN_FILENO);
}
