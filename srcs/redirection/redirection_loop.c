/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:22:02 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 11:06:03 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

static bool	out_files(t_redir *redir, char *file)
{
	if (file)
	{
		close(redir->fd_out);
		redir->fd_out = -1;
		return (true);
	}
	else
		return (false);
}

static bool	in_files(t_redir *redir, char *file)
{
	if (file)
	{
		close(redir->fd_in);
		redir->fd_in = -1;
		return (true);
	}
	else
		return (false);
}

static bool	status_out(int status, t_exec *data, int *idx)
{
	if (status == FILE_OUT)
	{
		if (out_files(&data->redir[*idx], data->redir[*idx + 1].file))
			;
		else
		{
			data->redir[0].fd_out = data->redir[*idx].fd_out;
			return (true);
		}
	}
	return (false);
}

static bool	status_in(int status, t_exec *data, int *idx)
{
	if (status == FILE_IN)
	{
		if (in_files(&data->redir[*idx], data->redir[*idx + 1].file))
			;
		else
		{
			data->redir[0].fd_in = data->redir[*idx].fd_in;
			return (true);
		}
	}
	return (false);
}

/*
**	Opens all the redirection files in one command and closes the previous
**	if there are more to be opened. Last one stays "active" and is used
**	later when FDs are set.
*/
bool	redirection_loop(t_exec *data)
{
	int	idx;
	int	status;

	idx = 0;
	status = -1;
	while (data->redir[idx].file)
	{
		status = redir_file_check(&data->redir[idx]);
		if (status_out(status, data, &idx) == true)
			return (true);
		else if (status_in(status, data, &idx) == true)
			return (true);
		idx++;
	}
	return (true);
}
