/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_branch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:37:47 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/03 10:53:14 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/execute.h"

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
			//if (redirection_loop(data))
			builtin_execute(shell, *data, env_cpy);
			close_fds(data->fds.fd_in, data->fds.fd_out);
		}
		else if (data->fds.pipe > -1)
			exec_fork_builtin(shell, data, env_cpy);
	}
	else if (data->cmd)
	{
		init_in_out_err(shell->tty);
		exec_real(data, env_cpy);
	}
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
		pid.wait = waitpid(0, &pid.status, 0);
	if ((branch->type == REDIR || branch->type == COMMAND))
		command_execution(shell, &branch->data, env_cpy);
	ft_arr_free((void *)&env_cpy);
	exec_branch(branch->left, shell);
	if (branch->type == PIPE)
		exec_branch(branch->right, shell);
	//init_in_out_err(shell->tty);
}
