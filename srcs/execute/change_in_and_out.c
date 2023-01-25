/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_in_and_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:14:41 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 18:31:13 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	pipe_ends(int pipe, int *fd_in, int *fd_out)
{
	if (pipe == PIPE_FIRST)
	{
		close(*fd_in);
		*fd_in = -1;
		dup2(*fd_out, STDOUT_FILENO);
		perror("error:"); // bad filedescriptor
		ft_putnbr_endl(*fd_out);
	}
	else if (pipe == PIPE_LAST)
	{
		close(*fd_out);
		*fd_out = -1;
		dup2(*fd_in, STDIN_FILENO);
	}
	DB;
}

static void	change_redir_io(t_redir	*redir)
{
	if (redir->type == FILE_IN || redir->type == FILE_TRUNC \
		|| redir->type == FILE_APPEND)
	{
		if (redir->fd_out > 0)
		{
			dup2(redir->fd_out, STDOUT_FILENO);
			close(redir->fd_out);
		}
		if (redir->fd_in > 0)
		{
			dup2(redir->fd_in, STDIN_FILENO);
			close(redir->fd_in);
		}
	}
}

/*
**	Closes the STDIN_FILENO or STDOUT_FILENO and sets the in and out
**	of the command to be executed for pipes and redirections.
*/
void	change_in_and_out(t_exec *data)
{
	if (data->fds.pipe != -1)
		pipe_ends(data->fds.pipe, &data->fds.fd_in, &data->fds.fd_out);
	else
	{
		if (data->fds.fd_out > 0 && data->redir->type != HEREDOC)
			dup2(data->fds.fd_out, STDOUT_FILENO);
		if (data->fds.fd_in > 0 && data->redir->type != HEREDOC)
			dup2(data->fds.fd_in, STDIN_FILENO);
	}
	change_redir_io(data->redir);
}
