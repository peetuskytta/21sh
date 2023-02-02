/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_rawmode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:59:48 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 22:18:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	enable_rawmode(t_shell *shell)
{
	struct termios	orig_raw;

	if (tcgetattr(STDIN_FILENO, &orig_raw) == -1)
		return (0);
	shell->orig_raw = orig_raw;
	shell->raw = orig_raw;
	shell->raw.c_iflag &= ~(IGNBRK | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
	shell->raw.c_cflag &= ~(CSIZE | PARENB);
	shell->raw.c_lflag &= ~(ICANON | ECHO);
	shell->raw.c_iflag &= ~(IXON | BRKINT);
	shell->raw.c_cc[VMIN] = 0;
	shell->raw.c_cc[VTIME] = 1;
	return (1);
}
/*
*/
