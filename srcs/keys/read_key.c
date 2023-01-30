/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:57:43 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 09:49:09 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	read_key(t_shell *shell, char *input)
{
	int	i;

	i = 0;
	while (i != 1)
	{
		ft_memset(input, 0, sizeof(char) * (MAX_BUFF + 1));
		i = read(STDIN_FILENO, input, MAX_BUFF);
		if (i == -1)
			return ;
		key_listen(shell, input);
	}
}
