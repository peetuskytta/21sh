/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:58:59 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/04 15:58:49 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

static bool	file_or_folders(char *str)
{
	if (ft_strchr(str, '/'))
		return (true);
	return (false);
}

void	redir_start(t_exec *data)
{
	int	idx;
	int	status;

	// check existence per data.str
	while (data->redir[idx].file != NULL)
	{
		if (file_or_folders(data->redir[idx].file))
		{
			//status = data->redir_folder_check();
			;//do the folder path check
		}
		else
			status = redir_file_check(data->redir[idx].file);
		if (status == GO)
			;
		// open the file
		idx++;
	}
	//DECIDE WHAT TO DO WITH THE LAST ITEM (CHANGE FDs already or after the fork)
}