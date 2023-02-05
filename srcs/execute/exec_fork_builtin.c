/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 07:54:05 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/05 17:01:30 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	builtin_redir(t_shell *shell, t_exec *data, char **env_cpy)
{
	change_in_and_out(data);
	if (ft_strequ(data->cmd, "env"))
	{
		if (builtin_env(shell, *data, env_cpy))
			;
	}
	else
		builtin_execute(shell, *data, env_cpy);
	close_fds(data->fds.fd_in, data->fds.fd_out);
	exit(EXIT_SUCCESS);
}

void	exec_fork_builtin(t_shell *shell, t_exec *data, char **env_cpy)
{
	data->pid.child = fork();
	if (data->pid.child == 0)
	{
		if (redirection_loop(data))
			builtin_redir(shell, data, env_cpy);
	}
	else if (data->pid.child < 0)
		ft_perror(FORK_FAIL);
	else
	{
		wait(0);
		close_fds(data->fds.fd_in, data->fds.fd_out);
	}
}
