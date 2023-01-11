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

static void	reset_terminal(char *terminal)
{
	close(STDIN_FILENO);
	open(terminal, O_RDWR);
	close(STDOUT_FILENO);
	open(terminal, O_RDWR);
	close(STDERR_FILENO);
	open(terminal, O_RDWR);
}

void	set_pipes(t_fds *fds, t_pipe *pipes, int idx)
{
	if (fds->pipe == PIPE_FIRST)
		fds->fd_out = pipes[idx].fd[1];
	if (fds->pipe == PIPE_LAST)
		fds->fd_in = pipes[idx - 1].fd[0];
	if (fds->pipe == -1)
	{
		fds->fd_in = pipes[idx - 1].fd[0];
		fds->fd_out = pipes[idx].fd[1];
	}
}

void	loop_pipes(t_ast *temp, t_pipe *pipes, int idx)
{
	if (temp == NULL)
		return ;
	if (temp->type == COMMAND || temp->type == REDIR)
	{
		//ft_putendl(temp->data.cmd);
		if (idx == 0)
			temp->data.fds.pipe = PIPE_FIRST;
		if (pipes[idx].fd[0] == -1)
			temp->data.fds.pipe = PIPE_LAST;
		set_pipes(&temp->data.fds, pipes, idx++);
		//ft_putnbr_endl(idx);
		//ft_printf("PIPE: [%d] IN: {%d}, OUT: {%d}\n\n", temp->data.fds.pipe, temp->data.fds.fd_in,temp->data.fds.fd_out);
	}
	loop_pipes(temp->left, pipes, idx++);
	if (temp->type == PIPE)
	{
		loop_pipes(temp->right, pipes, idx++);
	}
}

static void	open_pipes(t_ast *branch, t_pipe *pipes)
{
	t_ast	*temp;
	int	idx;

	idx = 0;
	temp = branch;
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

void	piping(t_ast *branch)
{
	t_ast	*temp;
	t_ast	*temp2;

	temp = branch->right;
	temp2 = branch;
	if (temp == NULL)
		return ;
	open_pipes(temp, branch->pipes);
	loop_pipes(temp2, branch->pipes, 0);
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
** Begin execution of tree or multiple trees. Calls the tree_execute function
** to work on each tree separately. Reset some data if needed?!
*/
void	exec_tree(t_ast **tree, t_shell *shell)
{
	int	idx;

	idx = 0;
	NL;
	while (tree[idx])
	{
		// DO EXPANSIONS HERE before going in to the tree or in each NODE?
		piping(tree[idx]);
		exec_branch(tree[idx], shell);
		ft_memdel((void *)&tree[idx]);
		reset_terminal(shell->tty);
		idx++;
	}
	ft_memdel((void *)&tree);
}
