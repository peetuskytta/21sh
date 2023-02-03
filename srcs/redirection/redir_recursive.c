/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:36:14 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/03 16:36:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redirection.h"

void	redir_recursive(t_ast *branch)
{
	t_ast	*temp;

	temp = branch;
	if (temp == NULL)
		return ;
	redirection_loop(&temp->data);
	redir_recursive(temp->left);
	redir_recursive(temp->right);
}
