/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 22:19:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_read(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	if (enable_rawmode(shell) == 0)
		ft_perror(TCGET_ERR);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
	read_key(shell, input);
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
}
