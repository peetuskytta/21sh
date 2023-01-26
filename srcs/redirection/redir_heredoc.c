/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:36:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/26 20:28:26 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

static void	read_heredoc(t_herfd *hdoc, char *input)
{
	if (hdoc->fd > 0)
	{
		if (heredoc_listen(hdoc, input) == -1)
		{
			if (ft_strilen(hdoc->input) > 0)
				ft_putstr_fd(hdoc->input, hdoc->fd);
			hdoc->end = 1;
		}
	}
}

static void	stdin_heredoc(t_herfd *hdoc, char *input)
{
	int	i;

	i = 0;
	while (i != 1)
	{
		ft_memset(input, '\0', sizeof(char) * (MAX_BUFF + 1));
		i = read(STDIN_FILENO, input, MAX_BUFF);
		if (i == -1)
			return ;
		read_heredoc(hdoc, input);
	}
}

static void	heredoc_reset(t_herfd *hdoc)
{
	ft_memset(hdoc->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	ft_memdel((void *)&hdoc->delim);
	hdoc->idx = 0;
	hdoc->end = 0;
	ft_memset(hdoc, '\0', sizeof(t_herfd));
}

static int	init_heredoc(t_herfd *hdoc, char *delim)
{
	struct winsize	win;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	hdoc->cols = win.ws_col;
	if (access(HERE_DOC, F_OK) == 0)
	{
		ft_perror(HEREDOC_EXIST);
		return (1);
	}
	hdoc->fd = open(HERE_DOC, O_RDWR | O_CREAT | O_APPEND, 0664);
	hdoc->idx = 0;
	hdoc->end = 0;
	hdoc->input = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	allocation_check((void *)&hdoc->input);
	ft_memset(hdoc->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	hdoc->delim = ft_strdup(delim);
	return (0);
}

void	redir_heredoc(t_tok *token)
{
	char	input[MAX_BUFF + 1];
	t_herfd	hdoc;

	ft_memset(&hdoc, '\0', sizeof(t_herfd));
	if (init_heredoc(&hdoc, token->next->str) == 1)
		return ;
	ft_putstr_fd("> ", STDOUT_FILENO);
	while (TRUE)
	{
		stdin_heredoc(&hdoc, input);
		if (hdoc.end == 1)
		{
			ft_strdel(&token->str);
			token->str = ft_strdup("<");
			ft_strdel(&token->next->str);
			ft_strdel(&hdoc.delim);
			token->next->str = ft_strdup(HERE_DOC);
			heredoc_reset(&hdoc);
			break ;
		}
	}
	if (close(hdoc.fd) < 0)
		ft_perror(FILE_CLOSE_ERR);
}
