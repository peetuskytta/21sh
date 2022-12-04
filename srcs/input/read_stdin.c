/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/04 11:44:55 by zraunio          ###   ########.fr       */
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
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
		read_key(shell, input);
		read_quote(shell);
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
	}
	kill_mode("exit", shell);
}
