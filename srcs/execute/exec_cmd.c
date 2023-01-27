/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:40:28 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/27 08:21:55 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
**	Closes all the filedescriptors. Moved to a separate function
**	to fit the NORM.
*/
static void	close_fds(int fd_in, int fd_out)
{
	if (fd_in >= 0)
		close(STDIN_FILENO);
	if (fd_out >= 0)
		close(STDOUT_FILENO);
}

void	wait_for_finish(t_pid *pid)
{
	pid->wait = waitpid(pid->child, &pid->status, 0);
	if (pid->wait == -1)
		ft_perror(WAITPID_FAIL);
}

/*
**	Performs input/output change before fork and execution of a command.
*/
void	exec_cmd(t_exec data, char *bin_path, char **env_cpy)
{
	data.pid.child = fork();
	if (data.pid.child == 0)
	{
		change_in_and_out(&data);
		if (execve(bin_path, data.args, env_cpy) == -1)
		{
			ft_perror(EXECVE_ERROR);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (data.pid.child < 0)
		ft_perror (FORK_FAIL);
	else
	{
		if (data.fds.pipe != PIPE_FIRST)
			wait_for_finish(&data.pid);
		close_fds(data.fds.fd_in, data.fds.fd_out);
	}
}
