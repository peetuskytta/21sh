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

/*
** Comments
*/
void	exec_branch(t_ast *branch, t_shell *shell)
{
	char	**env_cpy;

	if (branch == NULL)
	{
		ft_putendl("(null)");
		return ;
	}
	if (branch->left)
	{
		ft_printf("cmd: %s\n", branch->left->data.cmd);
		ft_printf("Curr node type: %d\n", branch->type);
		ft_printf("	left: %p", branch->left);
		ft_printf("	left type: %d\n", branch->left->type);
	}
	if (branch->right)
	{
		ft_printf("cmd: %s\n", branch->right->data.cmd);
		ft_printf("Curr node type: %d\n", branch->type);
		ft_printf("	right: %p", branch->right);
		ft_printf("	right type: %d\n", branch->right->type);
	}
	NL;
	env_cpy = copy_environment(shell->environ);
	if (branch->type == COMMAND && branch->right == NULL)
		exec_cmd_simple(branch->data, env_cpy);
	if (branch->type == REDIR)
		exec_cmd_redir(branch->data, env_cpy);
	exec_branch(branch->left, shell);
	if (branch->type == PIPE)
		exec_branch(branch->right, shell);
	ast_release(branch, env_cpy);
}

