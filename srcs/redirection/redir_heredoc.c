/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/24 09:02:44 by zraunio          ###   ########.fr       */
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

/*store the delimiter, heredoc listen needs to parse for it
**so perhaps need to save to a string?
** REDIR might be closing things before heredoc is finished
*/

	shell->fd = open(HERE_DOC, O_RDWR | O_CREAT | O_APPEND, 0664);
	shell->cmd_idx = 0;
	ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	shell->delim = ft_strdup(token->str);
	ft_putstr_fd("\n> ", STDOUT_FILENO);
	// signal_listen();
	// signal_runtime();
	while (1)
		read_key(shell, input, 1);
	ft_strdel(&token->str);
	ft_strdel(&shell->delim);
	token->str = ft_strdup(HERE_DOC);
}
