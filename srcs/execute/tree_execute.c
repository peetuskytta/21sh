/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:36:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 14:46:00 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

/*
** Begin execution of tree or multiple trees. Calls the tree_execute function
** to work on each tree separately. Reset some data if needed?!
*/
void	tree_execute(t_ast **tree, t_shell *shell)
{
	int	idx;

	idx = 0;
	while (tree[idx])
	{
		// DO EXPANSIONS HERE?
		branch_execute(tree[idx], shell);
		ft_memdel((void *)&tree[idx]);
		idx++;
	}
}