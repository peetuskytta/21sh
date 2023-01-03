/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:00:13 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 08:00:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

void	ast_release(t_ast *branch, char **env_path, char **env_cpy)
{
	if (env_path != NULL)
		ft_arr_free((void *)&env_path);
	ft_memdel((void *)&env_cpy);
	ft_memdel((void *)&branch->left);
	ft_memdel((void *)&branch->right);
	branch = NULL;
}
