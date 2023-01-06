/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:11:08 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/06 16:14:26 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

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

static void	open_redirection(t_redir *redir, int *status)
{
	if (redir->type == FILE_TRUNC)
	{
		if (access(redir->file, W_OK) == -1)
			*status = FILE_PERM;
		redir->fildes = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (redir->fildes < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (redir->fildes > 0)
			*status = GO;
	}
	if (redir->type == FILE_APPEND)
	{
		if (access(redir->file, W_OK) == -1)
			*status = FILE_PERM;
		redir->fildes = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0664);
		if (redir->fildes < 0 && *status != FILE_PERM)
			*status = NO_FILE;
		if (redir->fildes > 0)
			*status = GO;
	}
}

int	redir_file_check(t_redir *redir)
{
	int			status;

	status = -1;
	if (access(redir->file, F_OK) == 0 && !ft_is_directory(redir->file))
		open_redirection(redir, &status);
	else if (ft_is_directory(redir->file))
		status = FOLDER;
	else
		open_redirection(redir, &status);
	if (status != GO)
		file_error(&status, redir->file);
	ft_putnbr_endl(status);
	return (status);
}
