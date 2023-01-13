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
	while (data->redir[idx].file_in.file || data->redir[idx].file_out.file)
	{
		if (redir_file_check(&data->redir[idx]) == FILE_GO)
		{
			if (data->redir[idx + 1].file_out.file)
			{
				close(data->redir->file_out.file_fd);
				data->redir[idx].file_out.file_fd = -1;
			}
			if (data->redir[idx + 1].file_in.file)
			{
				close(data->redir->file_in.file_fd);
				data->redir[idx].file_in.file_fd = -1;
			}
			if (!data->redir[idx + 1].file_out.file || !data->redir[idx + 1].file_out.file)
			{
				data->redir[0].file_in.file_fd = data->redir[idx].file_in.file_fd;
				data->redir[0].file_out.file_fd = data->redir[idx].file_out.file_fd;
				return (true);
			}
		}
		else
			return (false);
		idx++;
	}
	return (true);
}