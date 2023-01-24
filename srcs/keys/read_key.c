/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:57:43 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/24 09:03:20 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	read_heredoc(t_shell *shell, char *input)
{
	if (shell->fd > 0)
	{
		if (heredoc_listen(shell, input) == -1)
		{
			if (ft_strilen(shell->input) > 0)
				ft_putstr_fd(shell->input, shell->fd);
			if (close(shell->fd) < 0)
				ft_perror(FILE_CLOSE_ERR);
		}
	}
}

void	read_key(t_shell *shell, char *input, int flg)
{
	int	i;

	i = 0;
	while (i != 1)
	{
		ft_memset(input, '\0', sizeof(char) * (MAX_BUFF + 1));
		i = read(STDIN_FILENO, input, MAX_BUFF);
		if (i == -1)
			return ;
		if (flg == 0)
			key_listen(shell, input);
		else if (flg == 1)
			read_heredoc(shell, input);
	}
}
