/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:37:16 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/13 11:37:16 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

t_ast	**ast_constructor(t_tok *token)
{
	t_ast	**tree;
	t_tok	*temp;
	int		i;

	i = 0;
	temp = token;
	if (token == NULL)
		return (NULL);
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * (BUFFER));
	allocation_check((void *)&tree);
	ft_memset((void **)tree, 0, sizeof(t_ast *) * (BUFFER));
	while (token)
	{
		tree[i++] = ast_create_tree(&token);
		if (token && token->type == CHAR_SEMICOLON)
			token = token->next;
	}
	token_list_free(temp);
	return (tree);
}
