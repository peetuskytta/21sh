/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/03 11:13:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	input_read(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	if (enable_rawmode(shell) == 0)
		ft_perror(TCGET_ERR);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw) == -1)
		ft_perror(TCGET_ERR);
	read_key(shell, input);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &shell->orig_raw) == -1)
		ft_perror(TCGET_ERR);
}
