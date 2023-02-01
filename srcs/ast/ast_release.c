/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:00:13 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 13:34:06 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

/*
** Recursive cleaning function for tree branches.
*/
void	ast_release(t_ast *branch)
{
	if (branch == NULL)
		return ;
	exec_clear_data(&branch->data);
	ast_release(branch->left);
	ast_release(branch->right);
	if (branch)
	{
		ft_memdel((void *)&branch->left);
		ft_memdel((void *)&branch->right);
	}
}
