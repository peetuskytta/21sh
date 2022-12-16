/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:51:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/17 13:21:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char	*ft_strerror(int errnum)
{
	if (errnum == MALLOC_ERRNO)
		return (MALLOC_FAIL);
	else if (errnum == FORK_ERRNO)
		return (FORK_FAIL);
	else if (errnum == EXECVE_ERRNO)
		return (EXECVE_ERROR);
	else if (errnum == SYNTAX_ERRNO)
		return (SYNTAX_ERR);
	else if (errnum == PERMISSION_ERRNO)
		return (CD_NO_ACCESS);
	else if (errnum == NOT_FOUND_ERRNO)
		return (NO_FILE_OR_DIR);
	else if (errnum == NOT_DIR_ERRNO)
		return (CD_NOT_DIR);
	else if (errnum == PIPE_ERRNO)
		return (PIPE_ERR);
	else if (errnum == REDIR_ERRNO)
		return (REDIR_ERR);
	else if (errnum == BAD_FD_ERRNO)
		return (BAD_FD);
	else if (errnum == ABORT_ERRNO)
		return (ABORTED_ERROR);
	else if (errnum == ENV_NAME_ERRNO)
		return (NAME_ERROR);
	else if (errnum == ENV_INVALID_ERRNO)
		return (INVALID_CHAR);
	else
		return("ERROR");
}
