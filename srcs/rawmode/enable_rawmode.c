/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_rawmode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:59:48 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/14 13:38:45 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	enable_rawmode(t_shell *shell)
{
	struct termios	orig_raw;
	if (tcgetattr(STDIN_FILENO, &orig_raw) == -1)
		return (0);
	shell->orig_raw = orig_raw;
	orig_raw.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR
		| ICRNL | IXON);
	orig_raw.c_cflag &= ~(CSIZE | PARENB);
	orig_raw.c_cflag |= CS8;
	orig_raw.c_lflag &= ~(ECHO | ICANON | ISIG);
	// orig_raw.c_lflag &= ~(ICANON | ECHO);
	// orig_raw.c_lflag |= ISIG;
	orig_raw.c_cc[VMIN] = 0;
	orig_raw.c_cc[VTIME] = 1;
	shell->raw = orig_raw;
	return (1);
}
