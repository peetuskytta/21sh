/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:28:31 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/12 14:53:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	kill_mode(const char *str, t_shell *shell)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &shell->raw) == -1)
		ft_perror(ERROR_EXIT);
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	if (ft_strequ(str, "exit") || ft_strequ(str, "\nexit\n"))
		ft_putstr_fd(str, STDOUT_FILENO);
	else
		ft_perror(str);
	ft_arr_free((void *)&shell->environ);
	history_create(shell->history);
	exit(EXIT_SUCCESS);
}
