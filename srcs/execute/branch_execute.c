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

void	branch_execute(t_ast *branch, t_shell *shell)
{
	char	**env_path;

	if (branch == NULL)
		return ;
	env_path = fetch_path_variable(shell->environ);
	if (branch->type == COMMAND)
		cmd_simple_execute(branch->data, env_path);
	else if (branch->type == REDIR)
		cmd_redir_execute(branch->data, env_path);
	branch_execute(branch->left, shell);
	branch_execute(branch->right, shell);
	if (env_path != NULL)
		ft_arr_free((void *)&env_path);
	ft_memdel((void *)&branch->left);
	ft_memdel((void *)&branch->right);
	branch = NULL; //sets the branch to NULL lol
	ft_putendl("End of execution.");
}

