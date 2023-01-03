/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:00:13 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 17:13:48 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

void	ast_release(t_ast *branch, char **env_cpy)
{
	if (env_cpy != NULL)
		ft_arr_free((void *)&env_cpy);
	ft_memdel((void *)&branch->left);
	ft_memdel((void *)&branch->right);
	branch = NULL;
}
