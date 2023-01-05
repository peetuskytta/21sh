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

static bool	file_or_folders(char *str)
{
	if (ft_strchr(str, '/'))
		return (true);
	return (false);
}

void	redir_open_file(t_redir redir)
{
	(void)redir;

}

void	redirection_loop(t_exec *data)
{
	int	idx;

	idx = 0;
	while (data->redir[idx].file != NULL)
	{
		if (file_or_folders(data->redir[idx].file))
		{
			//status = data->redir_folder_check();
			;//do the folder path check
		}
		else
		{
			if (redir_file_check(data->redir[idx].file) == GO)
			{
				redir_open_file(data->redir[idx]);
				if (data->redir[idx + 1].file)
					close(data->redir[idx].fildes);
			}
			else
				return ;
		}
		idx++;
	}
	//DECIDE WHAT TO DO WITH THE LAST ITEM (CHANGE FDs already or after the fork)
}