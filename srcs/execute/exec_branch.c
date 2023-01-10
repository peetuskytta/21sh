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


static void	open_pipes(t_ast *branch)
{
	//t_fds	fds[MAX_REDIR];
	t_ast	*temp;
	int	fd[2];

	//ft_memset((void *)fds, -1, sizeof(t_fds) * MAX_REDIR);
	temp = branch;
	while (temp)
	{
		if ((temp->type == PIPE || temp->type == COMMAND || temp->type == REDIR) && temp->right != NULL)
		{
			if (pipe(fd) == -1)
				ft_perror(PIPE_ERR);
			else
			{
				temp->left->fds.fd_in = fd[FD_READ];
				temp->left->fds.fd_out = fd[FD_WRITE];
			}
		}
		temp = temp->right;
	}
}

/*
** Comments
*/
void	exec_branch(t_ast *branch, t_shell *shell)
{
	char	**env_cpy;
//	int		idx = 0;

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
		ft_printf("	right: %p", branch->right);
		ft_printf("	right type: %d\n", branch->right->type);
	}
	if (branch->right != NULL)
		open_pipes(branch->right);
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

