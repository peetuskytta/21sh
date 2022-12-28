/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/22 11:49:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void input_read(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	
	if (enable_rawmode(shell) == 0)
		ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
	read_key(shell, input);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
}
