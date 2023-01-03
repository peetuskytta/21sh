/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:33:45 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 08:34:35 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static char	**fetch_path_variable(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			return (ft_strsplit(*env + 5, ':'));
		env++;
	}
	return (NULL);
}

/*
** change the 100 env number to something real later.
*/
void	branch_execute(t_ast *branch, t_shell *shell)
{
	char	**env_path;
	char	**env_cpy;

	if (branch == NULL)
		return ;
	env_cpy = (char **)ft_memalloc(sizeof(char *) * 100);
	ft_memset((void *)env_cpy, 0, sizeof(char *) * 100);
	env_cpy = ft_memcpy(env_cpy, shell->environ, sizeof(char *) * 100);
	env_path = fetch_path_variable(shell->environ);
	if (branch->type == COMMAND)
		cmd_simple_execute(branch->data, env_path, env_cpy);
	else if (branch->type == REDIR)
		cmd_redir_execute(branch->data, env_path, env_cpy);
	branch_execute(branch->left, shell);
	branch_execute(branch->right, shell);
	ast_release(branch, env_path, env_cpy); // frees the path and copy of the environment, also the left and right pointers and sets the branch to NULL.
	ft_putendl("End of execution.");
}

