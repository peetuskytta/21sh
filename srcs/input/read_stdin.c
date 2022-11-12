/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/12 18:48:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char	*read_stdin(t_shell *shell)
{
	char	input[MAX_BUFF];
	int		key;

	while (1)
	{
		ft_memset(input, 0, MAX_BUFF);
		if (read(STDIN_FILENO, input, MAX_BUFF) == -1)
			kill_mode("read", shell);
		
	}
}
