/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:11:08 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/12 15:02:44 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

/*
**	Outputs the error message according to the status.
*/
static void	file_error(int *status, char *str)
{
	if (*status == FILE_PERM)
	{
		ft_perror("21sh:");
		ft_print_fd(STDERR_FILENO, " %s", str);
		ft_perror(EXEC_NO_ACCESS);
	}
	if (ft_is_directory(str) == 1)
	{
		ft_perror("21sh:");
		ft_print_fd(STDERR_FILENO, " %s", str);
		ft_perror(IS_A_DIR);
	}
	if (*status == NO_FILE)
	{
		ft_perror("21sh:");
		ft_print_fd(STDERR_FILENO, " %s", str);
		ft_perror(NO_FILE_OR_DIR);
	}
	*status = FILE_ERR;
}

static void	open_file_in(t_redir *redir, int *status)
{
	if (access(redir->file, R_OK) == -1)
		*status = FILE_PERM;
	redir->fd_in = open(redir->file, O_RDONLY);
	if (redir->fd_in < 0 && *status != FILE_PERM)
		*status = NO_FILE;
	if (redir->fd_in > 0)
		*status = FILE_GO;
}

/*
**	Opens file to write in APPEND or TRUNCATE mode. Checks existense
**	and file permissions and sets the status for later use.
**	In case of a file in open it for reading only.
*/
static void	open_redirections(t_redir *redir, int *status)
{
	if (redir->type_out == FILE_TRUNC)
	{
		if (access(redir->file, W_OK) == -1)
			*status = FILE_PERM;
		redir->fd_out = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (redir->fd_out < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (redir->fd_out > 0)
			*status = FILE_GO;
	}
	if (redir->type_out == FILE_APPEND)
	{
		if (access(redir->file, W_OK) == -1)
			*status = FILE_PERM;
		redir->fd_out = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0664);
		if (redir->fd_out < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (redir->fd_out > 0)
			*status = FILE_GO;
	}
	 if (redir->type_in == FILE_IN)
		open_file_in(redir, status);
}

/*
**	Checks that the redirection file is not a directory and if it exists
**	or not. Performs a set of checks and if all is fine status GO is returned.
*/
int	redir_file_check(t_redir *redir)
{
	int	status;

	status = -1;
	if (access(redir->file, F_OK) == 0 && !ft_is_directory(redir->file))
		open_redirections(redir, &status);
	else if (ft_is_directory(redir->file))
		status = FOLDER;
	else
		open_redirections(redir, &status);
	if (status != FILE_GO)
		file_error(&status, redir->file);
	return (status);
}
