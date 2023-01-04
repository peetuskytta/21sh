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

/*static int	count_semicolon(char *cmd_line)
{
	int	i;

	i = 0;
	while (*cmd_line)
	{
		if (*cmd_line == CHAR_SEMICOLON)
			i++;
		cmd_line++;
	}
	if (i == 0)
		return (1);
	return (i);
}*/

static bool	ast_sniff_for_pipe(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == CHAR_PIPE)
			return (false);
		if (tmp->type == CHAR_SEMICOLON)
			break ;
		tmp = tmp->next;
	}
	return (true);
}

static int	ast_sniff_for_type(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	if (!tmp)
		return(COMMAND);
	while (tmp->type != CHAR_SEMICOLON || tmp->type != PIPE)
	{
		tmp = tmp->next;
		if (!tmp)
			return(COMMAND);
		else if (tmp->type == REDIR)
			return (REDIR);
	}
	return (COMMAND);
}

static t_ast	*ast_create_pipe(int type)
{
	t_ast	*branch;

	branch = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&branch);
	branch->type = type;
	branch->right = NULL;
	branch->left = NULL;
	return (branch);
}

static t_ast	*ast_create_left(t_tok ***token, t_ast *branch)
{
	branch = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&branch);
	branch->type = ast_sniff_for_type((**token));
	ft_memset(&branch->data.redir, 0, sizeof(t_redir) * 512);
	ast_consume_tokens(token, branch, 0);
	branch->right = NULL;
	branch->left = NULL;
	return (branch);
}

static t_ast	*ast_create_tree(t_tok **token)
{
	t_ast	*branch;

	branch = ast_create_pipe(PIPE);
	branch->left = ast_create_left(&(token), branch);
	if (!(*token) || (*token)->type == CHAR_SEMICOLON)
		return (branch);
	if (ast_sniff_for_pipe((*token)->next))
	{
		(*token) = (*token)->next;
		branch->right = ast_create_left(&(token), branch);
	}
	else if ((*token)->type == CHAR_PIPE)
	{
		(*token) = (*token)->next;
		branch->right = ast_create_tree(token);
	}
	return (branch);
}

//DELETE BEFORE SUBMIT
void	print_tree(t_ast **tree)
{
	t_ast **tmp;
	int	i;

	tmp = tree;
	i = 0;
	while (tmp[i])
	{
		ft_printf("\ntree[%d]\n", i);
		ast_print(tmp[i]);
		i++;
		if (!tmp[i])
			ft_putendl("Root of the tree reached");
	}
}

t_ast	**ast_constructor(t_shell *shell, t_tok *token)
{
	t_ast	**tree;
	t_tok	*temp;
	int		i;

	i = 0;
	(void)shell;
	if (!token)
		return (NULL);
	temp = token;
<<<<<<< HEAD
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * (50));
	ft_memset((void **)tree, 0, sizeof(t_ast *) * (50));
	while (token)
	{
		tree[i++] = ast_create_tree(&token);
		if (token && token->type == CHAR_SEMICOLON)
			token = token->next;
=======
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * (count + 1));
	// NL;
	while (token)
	{
		if (!token)
			DB;
		// ft_printf("tree[%d]: first token: %s\n", i, token->str);
		tree[i] = ast_build_tree(&token);
		if (token && token->type == CHAR_SEMICOLON)
			token = token->next;
		if (!token)
		{
			// ft_putendl("END of token stream");
			break ;
		}
		i++;
>>>>>>> cursor
	}
	//print_tree(tree);
	token_list_free(temp);
	return (tree);
}

/*
ls -la >>file
tok >
tok >
tok file
tok  ls -la 2&>1 jee
	 ls -la > jee 2>&1
	 ls -la > jee .ls
*/
