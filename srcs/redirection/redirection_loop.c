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
	while (data->redir[idx].file)
	{
		if (redir_file_check(&data->redir[idx]) == GO)
		{
			if (data->redir[idx + 1].file)
			{
				close(data->redir->fildes);
				data->redir[idx].fildes = -1;
			}
			else
			{
				data->redir[0].fildes = data->redir[idx].fildes;
				return (true);
			}
		}
		else
			return (false);
		idx++;
	}
	return (true);
}