/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/20 12:39:18 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

bool	heredoc_write(int fd, char *delim)
{
	char	*here_string = ft_memalloc(sizeof(char *));
	char	temp[4096];
	int		bytes;

	ft_printf("\ndelimiter: %s\n", delim);
	bytes = read(STDIN_FILENO, &temp, 4096);
	if (bytes >= 0)
	{
		while (true)
		{
			get_next_line(fd, &here_string);
			{
				if (ft_strequ(delim, here_string) == 1)
					break ;
			}
			ft_putstr_fd(here_string, fd);
			ft_memdel((void *)&here_string);
		}
	}
	ft_memdel((void *)&here_string);
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
