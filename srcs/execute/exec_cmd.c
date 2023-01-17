/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:40:28 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/17 12:52:22 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
**	Closes the STDIN_FILENO or STDOUT_FILENO for the start and end of the pipe
**	We don't want to read in the pipe beginning and write to the pipe end.
*/
static void pipe_ends(int pipe, int *fd_in, int *fd_out)
{
	if (pipe == PIPE_FIRST)
	{
		*fd_in = -1;
		dup2(*fd_out, STDOUT_FILENO);
	}
	else if (pipe == PIPE_LAST)
	{
		*fd_out = -1;
		dup2(*fd_in, STDIN_FILENO);
	}
}

/*
**	Closes the STDIN_FILENO or STDOUT_FILENO and sets the in and out
**	of the command to be executed for pipes and redirections.
*/
static void	change_in_and_out(t_exec *data)
{
	if (data->fds.pipe != -1)
		pipe_ends(data->fds.pipe, &data->fds.fd_in, &data->fds.fd_out);
	else
	{
		if (data->fds.fd_out > 0)
			dup2(data->fds.fd_out, STDOUT_FILENO);
		if (data->fds.fd_in > 0)
			dup2(data->fds.fd_in, STDIN_FILENO);
	}
	if (data->redir->type == FILE_IN || data->redir->type == FILE_TRUNC \
		|| data->redir->type == FILE_APPEND)
	{
		if (data->redir->fd_out > 0)
		{
			dup2(data->redir->fd_out, STDOUT_FILENO);
			close(data->redir->fd_out);
		}
		if (data->redir->fd_in > 0)
		{
			dup2(data->redir->fd_in, STDIN_FILENO);
			close(data->redir->fd_in);
		}
	}
}

/*
**	Closes all the filedescriptors. Moved to a separate function
**	to fit the NORM.
*/
static void close_fds(int fd_in, int fd_out)
{
	if (fd_in > 0)
		close(fd_in);
	if (fd_out > 0)
		close(fd_out);
}

static void	wait_for_finish(t_pid *pid)
{
	pid->wait = waitpid(pid->child, &pid->status, 0);
	if (pid->wait == -1)
		ft_perror(WAITPID_FAIL);
}

/*
**	Performs input/output change before fork and execution of a command.
*/
void	exec_cmd(t_exec data, char *bin_path, char **env_cpy, int *output)
{
	t_pid	pid;

	(void)output;
	pid.child = fork();
	if (pid.child == 0)
	{
		change_in_and_out(&data);
		if (execve(bin_path, data.args, env_cpy) == -1)
		{
			ft_perror(EXECVE_ERROR);
			exit(EXIT_FAILURE);
		}
		close_fds(data.fds.fd_in, data.fds.fd_out);
		exit(EXIT_SUCCESS);
	}
	else if (pid.child < 0)
		ft_perror(FORK_FAIL);
	else
		wait_for_finish(&pid);
	close_fds(data.fds.fd_in, data.fds.fd_out);
}
