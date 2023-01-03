/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:18:29 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 15:25:27 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static char	**fetch_path_variable(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			return (ft_strsplit(*env + 5, ':'));
		env++;
	}
	return (NULL);
}

static void	clear_data(t_exec *data, char *path)
{
	int	i;

	i = 0;
	while (data->args[i])
		ft_strdel((void *)&data->args[i++]);
	if (path)
		ft_strdel((void *)&path);
	if (data->cmd)
		ft_strdel((void *)&data->cmd);
}

static void	execute_cmd(t_exec data, char *bin_path, char **env_cpy)
{
	t_pid	pid;

	pid.child = fork();
	if (pid.child == 0)
	{
		if (execve(bin_path, data.args, env_cpy) == -1)
		{
			ft_perror(EXECVE_ERROR);
			exit(EXIT_FAILURE);
		}
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

static bool	path_check(char *bin_path, char *cmd)
{
	if (access(bin_path, F_OK) == -1)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_perror(CMD_NOT_FOUND);
		return (false);
	}
	return (true);
}

// if no binary found set ERRNO and STDERR "no command found"
// builtin OR binary (maybe function pointers?)
void	cmd_simple_execute(t_exec data, char **env_cpy)
{
	char *bin_path;

	bin_path = fetch_binary_path(fetch_path_variable(env_cpy), data.cmd);
	if (path_check(bin_path, data.cmd))
		execute_cmd(data, bin_path, env_cpy);
	clear_data(&data, bin_path);
}