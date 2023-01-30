/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_branch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:33:45 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 08:34:35 by pskytta          ###   ########.fr       */
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

static void	wait_closefd(t_exec *data)
{
	wait(0);
	close_fds(data->fds.fd_in, data->fds.fd_out);
}

/*
**	Begins the process of finding the binary, opening redirections, checking
**	binary file's execution rights before executing the command.
**	Clears data after each command, succesful or not.
*/
static void	command_execution(t_shell *shell, t_exec *data, char **env_cpy)
{
	if (is_builtin(data->cmd) == true)
	{
		if (data->fds.pipe < 0)
		{
			if (redirection_loop(data))
				builtin_execute(shell, *data, env_cpy);
			close_fds(data->fds.fd_in, data->fds.fd_out);
		}
		else if (data->fds.pipe > -1)
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
				wait_closefd(data);
		}
	}
	else if (data->cmd)
		exec_real(data, env_cpy);
}

/*
**	Recursive approach to execute the commands in the tree branches. First
**	call itself on the left branch (where command info is stored) and then
**	if the right is valid it calls itself on the right and continues.
**	ast_release will clear the branch.
*/
void	exec_branch(t_ast *branch, t_shell *shell)
{
	char	**env_cpy;
	t_pid	pid;

	if (branch == NULL)
		return ;
	pid.child = branch->data.pid.child;
	env_cpy = copy_environment(shell->environ);
	if (branch->data.fds.pipe == PIPE_LAST)
		pid.wait = waitpid(-1, &pid.status, 0);
	if ((branch->type == REDIR || branch->type == COMMAND))
		command_execution(shell, &branch->data, env_cpy);
	exec_branch(branch->left, shell);
	if (branch->type == PIPE)
		exec_branch(branch->right, shell);
	ast_release(branch, env_cpy);
}
