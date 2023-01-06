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

static bool	redir_folders(char *str)
{
	if (ft_strchr(str, '/'))
		return (true);
	return (false);
}

bool	redirection_loop(t_exec *data)
{
	int	idx;

	idx = 0;
	while (data->redir[idx].file)
	{
		if (redir_folders(data->redir[idx].file))
		{
			//status = data->redir_folder_check();
			;//do the folder path check
		}
		else if (redir_file_check(&data->redir[idx]) == GO)
		{
			if (data->redir[idx + 1].file)
			{
				close(data->redir[idx].fildes);
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
	return (false);
	//DECIDE WHAT TO DO WITH THE LAST ITEM (CHANGE FDs already or after the fork)
}