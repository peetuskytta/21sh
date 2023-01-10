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

static void pipe_last_first(int pipe, int *fd_in, int *fd_out)
{
	if (pipe == PIPE_FIRST)
	{
		close(*fd_in);
		*fd_in = -1;
	}
	else if (pipe == PIPE_LAST)
	{
		close(*fd_out);
		*fd_out = -1;
	}
}

static void	change_io(t_exec *data)
{
	if (data->fds.pipe != -1)
		pipe_last_first(data->fds.pipe, &data->fds.fd_in, &data->fds.fd_out);
	else
	{
		if (data->fds.fd_out > 0)
		{
			dup2(data->fds.fd_out, STDOUT_FILENO);
			close(data->fds.fd_out);
		}
		if (data->fds.fd_in > 0)
		{
			dup2(data->fds.fd_in, STDIN_FILENO);
			close(data->fds.fd_in);
		}
	}
	if (data->redir->file != NULL) //not working with infile yet
		dup2(data->redir->fildes, STDOUT_FILENO);
	close (data->redir->fildes);
}

static void	execute_command(t_exec data, char *bin_path, char **env_cpy)
{
	t_pid	pid;

	pid.child = fork();
	if (pid.child == 0)
	{
		change_io(&data);
		if (execve(bin_path, data.args, env_cpy) == -1)
		{
			ft_perror(EXECVE_ERROR);
			exit(EXIT_FAILURE);
		}
		close (data.redir->fildes);
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
}

void	exec_cmd(t_exec data, char **env_cpy)
{
	char	*bin_path;

	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data.cmd);
	if (redirection_loop(&data) && exec_binary_check(bin_path, data.cmd))
		execute_command(data, bin_path, env_cpy);
	exec_clear_data(&data, bin_path);
}
