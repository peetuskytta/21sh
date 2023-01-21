/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/21 14:18:10 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

/* bool	heredoc_write(int fd, char *delim)
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
} */

void	redir_heredoc(t_shell *shell, t_tok *token)
{
	char	input[MAX_BUFF + 1];

	ft_putstr_fd("\n> ", STDOUT_FILENO);
	read_key(shell, input, 1);
	ft_strdel(&token->str);
	token->str = ft_strdup(HERE_DOC);
}
