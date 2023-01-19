/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/19 22:39:36 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

static bool	heredoc_write(int fd, char *delim)
{
	char	here_string[MAX_BUFF];
	t_pid	pid;

	pid.child = fork();
	if (pid.child > 0)
	{
		while (true)
		{
			if (read(STDIN_FILENO, &here_string, 4096) > 0)
			{
				if (ft_strequ(delim, here_string) == 1)
					break ;
			}
			ft_putstr_fd(here_string, fd);
		}
		exit(0);
	}
	wait(0);
	return (true);
}

void	redir_heredoc(t_exec *data)
{
	int	fd;

	ft_putendl(data->redir->file); // DELIMITER is the file
	fd = open(HERE_DOC, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd > 0)
	{
		if (heredoc_write(fd, data->redir->file) == false)
		{
			exit(1);
		}
		else
			DB;
	}
	if (close(fd) < 0)
		ft_perror(FILE_CLOSE_ERR);
}
