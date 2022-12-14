/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:15:33 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 17:38:02 by pskytta          ###   ########.fr       */
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
		if (data->fds.fd_out >= 0)
			dup2(data->fds.fd_out, STDOUT_FILENO);
		if (data->fds.fd_in >= 0)
			dup2(data->fds.fd_in, STDIN_FILENO);
	}
	if (data->redir->file != NULL) //not working with infile yet
	{
		dup2(data->redir->fildes, STDOUT_FILENO);
		close(data->redir->fildes);
	}
}

/*
**	Closes all the filedescriptors. Moved to a separate function
**	to fit the NORM.
*/
static void close_fds(int fd_in, int fd_out)
{
	if (fd_in >= 0)
		close(fd_in);
	if (fd_out >= 0)
		close(fd_out);
}

/*
**	Performs input/output change before fork and execution of a command.
*/
void	exec_cmd(t_exec data, char *bin_path, char **env_cpy)
{
	t_pid	pid;

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
		close(data.redir->fildes);
		exit(EXIT_SUCCESS);
	}
	else if (pid.child < 0)
		ft_perror(FORK_FAIL);
	else
	{
		pid.wait = waitpid(pid.child, &pid.status, 0);
		if (pid.wait == -1)
			ft_perror(WAITPID_FAIL);
	}
	close_fds(data.fds.fd_in, data.fds.fd_out);
}
