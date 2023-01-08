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
	return (copy);
}


void	open_pipes(t_ast *branch, char **env_cpy)
{
	int		fd[2];
	t_pid	pid[2];

	if (pipe(fd) < 0)
		ft_perror(PIPE_ERR);
	pid[0].child = fork();
	if (pid[0].child == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd_redir(branch->left->data, env_cpy);
		exit(1);
	}
	pid[1].child = fork();
	if (pid[1].child == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd_redir(branch->right->data, env_cpy);
		exit(1);
	}
	else if (pid[0].child < 0 || pid[1].child < 0)
		ft_perror(FORK_FAIL);
	else
	{
		close(fd[1]);
		close(fd[0]);
		pid[0].wait = waitpid(pid[0].child, &pid[0].status, 0);
		pid[1].wait = waitpid(pid[1].child, &pid[1].status, 0);
	}
	//wait(0);
	//wait(0);
}

void	reset_terminal(char *terminal)
{
	close(STDIN_FILENO);
	open(terminal, O_RDWR);
	close(STDOUT_FILENO);
	open(terminal, O_RDWR);
	close(STDERR_FILENO);
	open(terminal, O_RDWR);
}

/*
** Comments
*/
void	exec_branch(t_ast *branch, t_shell *shell)
{
	char	**env_cpy;

	if (branch == NULL)
		return ;
	if (branch->left)
	{
		ft_printf("cmd: %s\n", branch->left->data.cmd);
		ft_printf("	left: %p", branch->left);
		ft_printf("	left type: %d\n", branch->left->type);
	}
	if (branch->right)
	{
		ft_printf("cmd: %s\n", branch->right->data.cmd);
		ft_printf("	right: %p", branch->right);
		ft_printf("	right type: %d\n", branch->right->type);
	}
	NL;
	env_cpy = copy_environment(shell->environ);
	if ((branch->type == REDIR || branch->type == COMMAND) && branch->right == NULL)
		exec_cmd_redir(branch->data, env_cpy);
	if (branch->left && branch->right == NULL)
		exec_branch(branch->left, shell);
	if (branch->right)
	{
 		//if (branch->type == PIPE)
		//{
			ft_putendl("\nPIIPPUINEN");
			open_pipes(branch, env_cpy);
			reset_terminal(shell->tty);
		//}
		//exec_branch(branch->right, shell);
	}
	ast_release(branch, env_cpy);
}

