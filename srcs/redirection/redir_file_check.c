/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:11:08 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/13 11:08:20 by pskytta          ###   ########.fr       */
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

/*
**	Opens file to write in APPEND or TRUNCATE mode. Checks existense
**	and file permissions and sets the status for later use.
*/
static void	open_redirection_out(t_file *out, int *status)
{
	if (out->type == FILE_TRUNC)
	{
		if (access(out->file, W_OK) == -1)
			*status = FILE_PERM;
		out->file_fd = open(out->file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (out->file_fd < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (out->file_fd > 0)
			*status = GO;
	}
	if (out->type == FILE_APPEND)
	{
		if (access(out->file, W_OK) == -1)
			*status = FILE_PERM;
		out->file_fd = open(out->file, O_CREAT | O_WRONLY | O_APPEND, 0664);
		if (out->file_fd < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (out->file_fd > 0)
			*status = GO;
	}
}

static void	open_redirection_in(t_file *in, int *status)
{
	if (in->type == FILE_IN)
	{
		if (access(in->file, W_OK) == -1)
			*status = FILE_PERM;
		in->file_fd = open(in->file, O_RDONLY);
		if (in->file_fd < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (in->file_fd > 0)
			*status = GO;
	}
}

/*
**	Checks that the redirection file is not a directory and if it exists
**	or not. Performs a set of checks and if all is fine status GO is returned.
*/
int	redir_file_check(t_redir *redir)
{
	int			status;

	status = -1;
	if (redir->file_out.file)
	{
		if (access(redir->file_out.file, F_OK) == 0 && !ft_is_directory(redir->file_out.file))
			open_redirection_out(&redir->file_out, &status);
		else if (ft_is_directory(redir->file_out.file))
			status = FOLDER;
		else
			open_redirection_out(redir, &status);
		if (status != GO)
			file_error(&status, redir->file_out.file);
	}
	if (redir->file_in.file)
	{
		if (access(redir->file_in.file, F_OK) == 0 && !ft_is_directory(redir->file_in.file))
			open_redirection_in(&redir->file_in, &status);
		else
			status = NO_FILE;
		if (status != GO)
			file_error(&status, redir->file_in.file);
	}
	return (status);
}
