/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/20 08:30:11 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

bool	heredoc_write(int fd, char *delim)
{
	char	here_string[MAX_BUFF];

	ft_printf("delimiter: %s\n", delim);
	while (true)
	{
		if (read(STDIN_FILENO, &here_string, 4096) >= 0)
		{
			if (ft_strequ(delim, here_string) == 1)
				break ;
		}
		ft_putstr_fd(here_string, fd);
	}
	return (true);
}

void	redir_heredoc(t_tok *token)
{
	int	fd;

	//ft_putendl(token->str); // DELIMITER is the file
	fd = open(HERE_DOC, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd > 0)
	{
		heredoc_write(fd, token->str);
	}
	if (close(fd) < 0)
		ft_perror(FILE_CLOSE_ERR);
}
