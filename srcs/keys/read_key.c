/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:57:43 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 10:01:18 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	read_heredoc(t_shell *shell, char *input)
{
	int	fd;

	fd = open(HERE_DOC, O_RDWR | O_CREAT | O_APPEND, 0664);
	if (fd > 0)
	{
		if (heredoc_listen(shell, input, fd) == -1)
		{
			if (close(fd) < 0)
				ft_perror(FILE_CLOSE_ERR);
		}
	}
	if (close(fd) < 0)
		ft_perror(FILE_CLOSE_ERR);
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
