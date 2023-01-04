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
		return ;
	env_cpy = copy_environment(shell->environ);
	if (branch->type == COMMAND)
		exec_cmd_simple(branch->data, env_cpy);
	else if (branch->type == REDIR)
		exec_cmd_redir(branch->data, env_cpy);
	exec_branch(branch->left, shell);
	exec_branch(branch->right, shell);
	ast_release(branch, env_cpy);
	//ft_putendl("End of execution.");
}
