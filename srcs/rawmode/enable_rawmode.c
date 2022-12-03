/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_rawmode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:59:48 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/03 16:56:31 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	enable_rawmode(t_shell *shell)
{
	struct termios	orig_raw;

	if (tcgetattr(STDIN_FILENO, &orig_raw) == -1)
		return (0);
	shell->orig_raw = orig_raw;
	orig_raw.c_lflag &= ~(ECHO | ICANON | ISIG);
	shell->raw = orig_raw;
	return (1);
}
