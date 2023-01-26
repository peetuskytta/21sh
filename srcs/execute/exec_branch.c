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
**	copies the environment for the execution. Used to change environment
**	before execution so we don't mess up the parent's environment.
*/
static char	**copy_environment(char **environ)
{
	char	**copy;
	int		i;

	i = env_variable_counter(environ);
	copy = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	ft_memset(copy, 0, (i + 2));
	i = 0;
	while (environ[i])
	{
		copy[i] = ft_strdup(environ[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	real_exec(t_exec *data, char **env_cpy)
{
	char	*bin_path;

	bin_path = NULL;
	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data->cmd);
	if (redirection_loop(data) && exec_binary_check(bin_path, *data))
		exec_cmd(*data, bin_path, env_cpy);
	ft_strdel((void *)&bin_path);
}

static void	close_fds(int fd_in, int fd_out)
{
	if (fd_in >= 0)
		close(fd_in);
	if (fd_out >= 0)
		close(fd_out);
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
		data->pid.child = fork();
		if (data->pid.child == 0)
		{
			if (redirection_loop(data))
			{
				change_in_and_out(data);
				if (ft_strequ(data->cmd, "env"))
				{
					if (builtin_env(shell, *data, env_cpy)) // work it so that things are changed for the env to
						{} ;
				}
				else
					builtin_execute(shell, *data, env_cpy);
				close_fds(data->fds.fd_in, data->fds.fd_out);
				exit(EXIT_SUCCESS);
			}
		}
		else if (data->pid.child < 0)
			ft_perror(FORK_FAIL);
		else
			close(data->fds.fd_out);
	}
	else
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
	if (branch->data.fds.pipe == PIPE_LAST)
			pid.wait = waitpid(branch->data.process_pid, &pid.status, 0);
	env_cpy = copy_environment(shell->environ);
	if ((branch->type == REDIR || branch->type == COMMAND))
		command_execution(shell, &branch->data, env_cpy);
	exec_branch(branch->left, shell);
	if (branch->type == PIPE)
		exec_branch(branch->right, shell);
	ast_release(branch, env_cpy);
}
