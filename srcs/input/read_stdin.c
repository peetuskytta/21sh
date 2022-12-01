/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/01 16:08:47 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void read_stdin(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	write(1, "$> ", 4);
	while (TRUE)
	{
		if (enable_rawmode(shell) == 0)
			ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
		read_key(shell, input);
		read_quote(shell);
		ft_putendl(shell->cmd_line);
	}
	kill_mode("exit", shell);
}
