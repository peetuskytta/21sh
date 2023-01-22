/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 16:27:55 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_read(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	if (enable_rawmode(shell) == 0)
		ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
	read_key(shell, input, 0);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
}
