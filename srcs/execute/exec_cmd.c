/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:40:28 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 16:47:48 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
**	Closes the STDIN_FILENO or STDOUT_FILENO for the start and end of the pipe
**	We don't want to read in the pipe beginning and write to the pipe end.
*/
/* static void	pipe_ends(int pipe, int *fd_in, int *fd_out)
{
	if (pipe == PIPE_FIRST)
	{
		close(*fd_in);
		*fd_in = -1;
		dup2(*fd_out, STDOUT_FILENO);
	}
	else if (pipe == PIPE_LAST)
	{
		close(*fd_out);
		*fd_out = -1;
		dup2(*fd_in, STDIN_FILENO);
	}
}

static void	change_redir_io(t_redir	*redir)
{
	if (redir->type == FILE_IN || redir->type == FILE_TRUNC \
		|| redir->type == FILE_APPEND)
	{
		if (redir->fd_out > 0)
		{
			dup2(redir->fd_out, STDOUT_FILENO);
			close(redir->fd_out);
		}
		if (redir->fd_in > 0)
		{
			dup2(redir->fd_in, STDIN_FILENO);
			close(redir->fd_in);
		}
	}
}


**	Closes the STDIN_FILENO or STDOUT_FILENO and sets the in and out
**	of the command to be executed for pipes and redirections.
*/
/*
static void	change_in_and_out(t_exec *data)
{
	if (data->fds.pipe != -1)
		pipe_ends(data->fds.pipe, &data->fds.fd_in, &data->fds.fd_out);
	else
	{
		if (data->fds.fd_out > 0 && data->redir->type != HEREDOC)
			dup2(data->fds.fd_out, STDOUT_FILENO);
		if (data->fds.fd_in > 0 && data->redir->type != HEREDOC)
			dup2(data->fds.fd_in, STDIN_FILENO);
	}
	change_redir_io(data->redir);
}*/

/*
**	Closes all the filedescriptors. Moved to a separate function
**	to fit the NORM.
*/
static void	close_fds(int fd_in, int fd_out)
{
	if (fd_in >= 0)
		close(fd_in);
	if (fd_out >= 0)
		close(fd_out);
}

static void	wait_for_finish(t_pid *pid)
{
	pid->wait = waitpid(pid->child, &pid->status, 0);
	if (pid->wait == -1)
		ft_perror(WAITPID_FAIL);
}

// static void	signal_stop(int signo)
// {
// 	(void)signo;
// }

// static void	signal_kill(t_pid pid)
// {
// 	kill(pid.child, SIGKILL);
// }

// static void	signal_abort(t_pid pid)
// {
// 	kill(pid.child, SIGABRT);
// }

/*
**	Performs input/output change before fork and execution of a command.
*/
void	exec_cmd(t_exec data, char *bin_path, char **env_cpy)
{
	data.pid.child = fork();	// store these in an array?
	if (data.pid.child == 0)	// in the CHILD process
	{
		change_in_and_out(&data);
		// copy stderr and stdout to different files.. then compare their
		// modification times to determine to where something was written
		// to and save it in shell->last_io as a boolean value;
		if (execve(bin_path, data.args, env_cpy) == -1)
		{
			ft_perror(EXECVE_ERROR);
			exit(EXIT_FAILURE);
		}
		close_fds(data.fds.fd_in, data.fds.fd_out);
		exit(EXIT_SUCCESS);
	}
	else if (data.pid.child < 0)
		ft_perror (FORK_FAIL);
	else	// in the PARENT process
	{
		if (data.fds.pipe != PIPE_FIRST)
			wait_for_finish(&data.pid);
	}
	close_fds(data.fds.fd_in, data.fds.fd_out);
}
