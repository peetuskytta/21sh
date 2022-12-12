/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 09:35:17 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void read_stdin(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	(void)write(1, "$> ", 4);
	while (TRUE)
	{
		if (enable_rawmode(shell) == 0)
			ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
		init_window(&shell->window);
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
		read_key(shell, input);
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
	}
	kill_mode("exit", shell);
}
