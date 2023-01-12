/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:36:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 17:42:57 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	save_pipe_fd(t_fds *fds, t_pipe *pipes, int idx)
{
	if (fds->pipe == PIPE_FIRST)
		fds->fd_out = pipes[idx].fd[PIPE_WRITE];
	if (fds->pipe == PIPE_LAST)
		fds->fd_in = pipes[idx - 1].fd[PIPE_READ];
	if (fds->pipe == -1)
	{
		fds->fd_in = pipes[idx - 1].fd[PIPE_READ];
		fds->fd_out = pipes[idx].fd[PIPE_WRITE];
	}
}

/*
**	Recursive setup_pipes changes the values of each command struct's
**	filedescriptors to correspond to the READ or WRITE end of the pipe.
*/
static void	setup_pipes(t_ast *temp, t_pipe *pipes, int idx)
{
	if (temp == NULL)
		return ;
	if (temp->type == COMMAND || temp->type == REDIR)
	{
		//ft_putendl(temp->data.cmd);
		if (idx == 0)
			temp->data.fds.pipe = PIPE_FIRST;
		if (pipes[idx].fd[PIPE_READ] == -1)
			temp->data.fds.pipe = PIPE_LAST;
		save_pipe_fd(&temp->data.fds, pipes, idx++);
		//ft_putnbr_endl(idx);
		//ft_printf("PIPE: [%d] IN: {%d}, OUT: {%d}\n\n", temp->data.fds.pipe, temp->data.fds.fd_in,temp->data.fds.fd_out);
	}
	setup_pipes(temp->left, pipes, idx++);
	if (temp->type == PIPE)
	{
		setup_pipes(temp->right, pipes, idx++);
	}
}
/*
*	Init_pipes function will open the correct number of pipes according to the
*	type of the branch. Command "ls -l | grep file" will have one pipe opened.
*/
static void	init_pipes(t_ast *temp, t_pipe *pipes)
{
	int	idx;

	idx = 0;
	while (temp)
	{
		if (temp->type == PIPE || temp->type == COMMAND || temp->type == REDIR)
		{
			if (pipe(pipes[idx++].fd) == -1)
				ft_perror(PIPE_ERR);
		}
		temp = temp->right;
	}
}

/*
**	Piping function calls the init_pipes and setup_pipes functions.
**	If branch->right (pointer to the next branch) equals NULL there
**	are no pipes and the function returns.
*/
static void	piping(t_ast *branch)
{
	t_ast	*temp;

	temp = branch->right;
	if (temp == NULL)
		return ;
	init_pipes(temp, branch->pipes);
	temp = branch;
	setup_pipes(temp, branch->pipes, 0);
/*	int idx = 0;
	while (branch->pipes[idx].fd[0] != -1 || branch->pipes[idx].fd[1] != -1)
	{
		ft_printf("pipes[%d]\n", idx);
		ft_printf("  READ:[%d],", branch->pipes[idx].fd[0]);
		ft_printf(" WRITE:[%d]\n", branch->pipes[idx].fd[1]);
		idx++;
	} */
}

/*
**	Begin execution of a tree or multiple trees. Tree consists of one
**	or multiple branches (if pipes are present). Terminal filedescriptors
**	STDIN_FILENO, STDOUT_FILENO, and STDERR_FILENO are reset after each
**	tree executed, just in case.
*/
void	exec_tree(t_ast **tree, t_shell *shell)
{
	int	idx;

	idx = 0;
	NL;
	while (tree[idx])
	{
		piping(tree[idx]);
		exec_branch(tree[idx], shell);
		ft_memdel((void *)&tree[idx]);
		init_in_out_err(shell->tty);
		idx++;
	}
	ft_memdel((void *)&tree);
}
