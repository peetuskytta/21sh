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

void	set_pipe(t_ast *temp2, t_pipe *pipes, int *idx)
{
	if (temp2->data.fds.pipe == PIPE_FIRST)
		temp2->data.fds.fd_out = pipes[*idx].fd[1];
	if (temp2->data.fds.pipe == PIPE_LAST)
		temp2->data.fds.fd_in = pipes[*idx].fd[1];
	if (temp2->data.fds.pipe == -1)
	{
		temp2->data.fds.fd_in = pipes[*idx].fd[1];
		temp2->data.fds.fd_out = pipes[*idx].fd[1];
	}
}

static void	open_pipes(t_ast *temp, t_pipe *pipes)
{
	int	idx;

	idx = 0;
	if (idx == 0)
		temp->data.fds.pipe = PIPE_FIRST;
	while (temp)
	{
		if (temp->type == PIPE || temp->type == COMMAND || temp->type == REDIR)
		{
			if (pipe(pipes[idx].fd) == -1)
				ft_perror(PIPE_ERR);
			idx++;
		}
		if (temp->right == NULL)
			temp->data.fds.pipe = PIPE_LAST;
		temp = temp->right;
	}
}

void	piping(t_ast *branch)
{
	t_ast	*temp;
	t_ast	*temp2;
	int		idx;

	idx = 0;
	temp = branch->right;
	temp2 = branch;
	open_pipes(temp, branch->pipes);
	while (temp2)
	{
		if (temp2->type == PIPE || temp2->type == COMMAND || temp2->type == REDIR)
		{
			set_pipe(temp2, branch->pipes, &idx);
			idx++;
		}
		temp2 = temp2->right;
	}
//	set_pipe(temp2, branch->pipes);
	ft_printf("OUT: %d\n", branch->data.fds.fd_out);
	ft_printf("OUT: %d\n", branch->right->data.fds.fd_out);
 	idx = 0;
	while (branch->pipes[idx].fd[0] != -1 || branch->pipes[idx].fd[1] != -1)
	{
		ft_printf("pipes[%d]\n", idx);
		ft_printf("  READ:[%d],", branch->pipes[idx].fd[0]);
		ft_printf(" WRITE:[%d]\n", branch->pipes[idx].fd[1]);
		idx++;
	}
}

/*
** Comments
*/
void	exec_branch(t_ast *branch, t_shell *shell)
{
	char	**env_cpy;

	if (branch == NULL)
		return ;
	// if (branch->left)
	// {
	// 	ft_printf("cmd: %s\n", branch->left->data.cmd);
	// 	ft_printf("	left: %p", branch->left);
	// 	ft_printf("	left type: %d\n", branch->left->type);
	// }
	// if (branch->right)
	// {
	// 	ft_printf("	right: %p", branch->right);
	// 	ft_printf("	right type: %d\n", branch->right->type);
	// }
	if (branch->right != NULL)
		piping(branch); // maybe here is problem
	env_cpy = copy_environment(shell->environ);
	if ((branch->type == REDIR || branch->type == COMMAND) && branch->right == NULL)
		exec_cmd(branch->data, env_cpy);
	if (branch->left && branch->right == NULL)
		exec_branch(branch->left, shell);
	if (branch->right)
	{
	//	if (branch->right->type == PIPE)
	//	{
	//		open_pipes(&fds[idx], idx); // copy data from branch->type PIPE to the branch->letf.fds (later used to change the IO of the cmd)
			branch = branch->right;
	//		idx++;
	//		change the fd in or out before exec.
			exec_branch(branch->left, shell);
	}
	ast_release(branch, env_cpy);
	//reset_terminal(shell->tty);
}

//ls -l | grep file | awk '{print $1, $9}'
//ls -l | grep file | grep Makefile | wc -l
//ls -l | grep file | grep Makefile | wc -l
