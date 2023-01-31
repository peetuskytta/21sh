/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:00:13 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 08:16:08 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

/*
** Recursive cleaning function for tree branches.
*/
void	ast_release(t_ast *branch, char **env_cpy)
{
	(void)env_cpy;
	if (branch == NULL)
		return ;
	exec_clear_data(&branch->data);
	ast_release(branch->left, env_cpy);
	ast_release(branch->right, env_cpy);
	if (branch)
	{
		ft_memdel((void *)&branch->left);
		ft_memdel((void *)&branch->right);
	}
}
