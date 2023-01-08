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

static void redir_change_io(int fildes)
{
	dup2(fildes, STDOUT_FILENO);
	close (fildes);
}

static void	execute_redir(t_exec data, char *bin_path, char **env_cpy)
{
	t_pid	pid;

	pid.child = fork();
	if (pid.child == 0)
	{
		if (data.redir->file != NULL)
			redir_change_io(data.redir->fildes);
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

static void	redirection_start(t_exec data, char *bin_path, char **env_cpy)
{
	if (redirection_loop(&data) && exec_binary_check(bin_path, data.cmd))
		execute_redir(data, bin_path, env_cpy);
	(void)env_cpy;
	(void)bin_path;
}

void	exec_cmd_redir(t_exec data, char **env_cpy)
{
	char	*bin_path;

	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data.cmd);
	redirection_start(data, bin_path, env_cpy);
	exec_clear_data(&data, bin_path);
}