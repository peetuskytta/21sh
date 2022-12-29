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
	//if (branch->type == COMMAND || branch->type == REDIR)
	branch->right = NULL;
	branch->left = NULL;
	return (branch);
}

static t_ast	*ast_build_tree(t_tok **token)
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
		branch->right = ast_build_tree(token);
	}
	return (branch);
}

static void ast_print(t_ast *tree)
{
	if (tree == NULL)
		return ;
	if (tree->type == COMMAND || tree->type == REDIR)
	{
		int ct = 0;
		while (tree->data.args[ct])
		{
			if (ct == 0)
				ft_putstr("CMD->  ");
			else
				ft_putstr("ARG->  ");
			ft_printf("%s\n", tree->data.args[ct++]);
		}
		if (tree->type == REDIR)
		{
			int i = 0;
			if (i == 0)
				ft_putstr("  RED->  |  ");
			while (tree->data.redir[i].file)
				ft_printf("%s  |  ", tree->data.redir[i++].file);
			NL;
		}
	}
	ast_print(tree->left);
	ast_print(tree->right);
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
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * 100);
	ft_memset((void **)tree, 0, sizeof(t_ast *) * 100);
	NL;
	while (token)
	{
		tree[i] = ast_build_tree(&token);
		if (token && token->type == CHAR_SEMICOLON)
		{
			token = token->next;
			i++;
		}
	}
	i = 0;
	while (tree[i])
	{
		ft_printf("\ntree[%d]\n", i);
		ast_print(tree[i]);
		i++;
	}
	ft_putendl("\nRoot of the tree reached");
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
