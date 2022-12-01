/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:28:31 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/01 17:03:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void kill_mode(const char *str, t_shell *shell)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &shell->raw) == -1)
		ft_perror(ERROR_EXIT);
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	ft_perror(str);
	exit(EXIT_SUCCESS);
}
