/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 18:17:26 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

void	redir_heredoc(t_shell *shell, t_tok *token)
{
	char	input[MAX_BUFF + 1];

	shell->fd = open(HERE_DOC, O_RDWR | O_CREAT | O_APPEND, 0664);
	shell->cmd_idx = 0;
	shell->end = 0;
	ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	shell->delim = ft_strdup(token->next->str);
	ft_putstr_fd("> ", STDOUT_FILENO);
	while (TRUE)
	{
		read_key(shell, input, 1);
		if (shell->end == 1)
		{
			ft_strdel(&token->str);
			token->str = ft_strdup("<");
			ft_strdel(&token->next->str);
			ft_strdel(&shell->delim);
			token->next->str = ft_strdup(HERE_DOC);
			break ;
		}
	}
	if (close(shell->fd) < 0)
		ft_perror(FILE_CLOSE_ERR);
}
