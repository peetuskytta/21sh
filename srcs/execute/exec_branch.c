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

/*
**	Checks the permissions for commands like "/bin/ls"
*/
static void	slash_access_check(t_exec *data, char **bin_path)
{
	if (access(data->cmd, F_OK) == -1)
	{
		ft_perror(NO_FILE_OR_DIR);
		return ;
	}
	else if (access(data->cmd, X_OK) == -1)
	{
		ft_perror(EXEC_NO_ACCESS);
		return ;
	}
	else
		*bin_path = ft_strdup(data->cmd);
}

static void	real_exec(t_exec *data, char **env_cpy)
{
	char	*bin_path;

	bin_path = NULL;
	if (data->cmd[0] == '/')
		slash_access_check(data, &bin_path);
	if (!bin_path)
		bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data->cmd);
	if (redirection_loop(data) && exec_binary_check(&bin_path, *data))
		exec_cmd(data, bin_path, env_cpy);
	else
		close_fds(data->fds.fd_in, data->fds.fd_out);
	ft_strdel((void *)&bin_path);
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
			{
				change_in_and_out(data);
				builtin_execute(shell, *data, env_cpy);
			}
			close_fds(data->fds.fd_in, data->fds.fd_out);
		}
		else if (data->fds.pipe > -1)
			exec_fork_builtin(shell, data, env_cpy);
	}
	else if (data->cmd)
		real_exec(data, env_cpy);
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
}
