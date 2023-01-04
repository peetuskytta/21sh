/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:11:08 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/04 15:52:31 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

int	redir_file_check(char *str)
{
	struct stat	buf;

	if (stat(str, &buf) != -1)
	{
		if (access(str, F_OK) && ft_is_directory(str) != 1)
		{
			if (access(str, X_OK))
				return (GO);
			else
				return (FILE_PERM);
		}
		else
			return (FOLDER);
	}
	return (NO_FILE);
}
