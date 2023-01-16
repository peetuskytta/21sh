/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:58:59 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/05 15:40:18 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

/*
**	Opens all the redirection files in one command and closes the previous
**	if there are more to be opened. Last one stays "active" and is used
**	later when FDs are set.
*/
bool	redirection_loop(t_exec *data)
{
	int	idx;

	idx = 0;
	while (data->redir[idx].file_in || data->redir[idx].file_out)
	{
		if (redir_file_check(&data->redir[idx]) == FILE_GO)
		{
			if (data->redir[idx + 1].file_out && data->redir[idx].type_out == FILE_OUT)
			{
				close(data->redir->fd_out);
				data->redir[idx].fd_out = -1;
			}
			else
			{
				data->redir[0].fd_out = data->redir[idx].fd_out;
				return (true);
			}
			if (data->redir[idx + 1].file_in && data->redir[idx].type_in == FILE_IN)
			{
				close(data->redir->fd_in);
				data->redir[idx].fd_in = -1;
			}
			else
			{
				data->redir[0].fd_in = data->redir[idx].fd_in;
				return (true);
			}
		}
		else
			return (false);
		idx++;
	}
	return (true);
}