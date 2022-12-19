/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:29:42 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 23:29:42 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

//static void	ast_release()
//static void	ast_execute()


static t_ast	*ast_build_branch(t_tok	*token)
{

}

t_ast	**ast_build_tree(t_shell *shell, t_tok *token)
{
	t_ast	**tree;
	t_tok	*head;
	int		i;
	(void)shell;
	(void)token;

	i = 0;
	head = token;
	ft_memset(&tree, 0, sizeof(t_ast));
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * \
		ft_count_chrstr(shell->cmd_line, CHAR_SEMICOLON) + 1);
	while (token)
	{
		tree[i] = ast_build_branch(token);
		if (token->type == SEPARATOR && token)
			token = token->next;
		i++;
	}
	tree[i] = NULL;
	token_list_free(head);
	return (tree);
}
