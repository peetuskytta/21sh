/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:11:08 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/05 16:08:13 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

static void	file_error(int status)
{
	if (status == FILE_PERM)
		ft_perror(EXEC_NO_ACCESS);
	else if (status == FOLDER)
		return ;
	else if (status == NO_FILE)
		ft_perror(NO_FILE_OR_DIR);
}

int	redir_file_check(char *str)
{
	struct stat	buf;
	int			status;

	if (stat(str, &buf) != -1)
	{
		if (access(str, F_OK) && ft_is_directory(str) != 1)
		{
			if (access(str, X_OK))
				return (GO);
			else
				status = FILE_PERM;
		}
		else
			status = FOLDER;
	}
	else
		status = NO_FILE;
	file_error(status);
	return (status);
}
