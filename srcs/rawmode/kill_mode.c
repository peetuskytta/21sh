/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:28:31 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/29 15:01:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inlcudes/shell.h"

void kill_mode(const char *str)
{
	write (STDOUT_FILENO, "\x1b[2J", 4);
	write (STDOUT_FILENO, "\x1b[H", 3);
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}
