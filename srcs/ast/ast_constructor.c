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

static int	count_semicolon(char *cmd_line)
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
}

static bool	ast_sniff_for_pipe(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == PIPE)
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

static void	ast_add_arguments(t_tok ***token, t_ast *branch, int *i)
{
	branch->data.args[(*i)++] = ft_strdup((**token)->str);
	//ft_putendl(branch->data.args[(*i)++]);
	(**token) = (**token)->next;
	if (branch->type == COMMAND)
		branch->data.redir = NULL;
}

static int	ast_redir_count(t_tok *token)
{
	t_tok	*tmp;
	int		count;

	count = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == REDIR)
			count++;
		else if (tmp->type == CHAR_SEMICOLON || (tmp->type == PIPE))
			break ;
		tmp = tmp->next;
	}
	return (count);
}

static void	ast_add_redir(t_tok ***token, t_redir *redir)
{
	redir->next = (t_redir *)ft_memalloc(sizeof(t_redir));
	allocation_check((void *)&branch->data.redir);
	if ()
	else if ()
	else
	redir->next = NULL;
}
 /*Consumes the tokens to arguments and redirections*/
static void	ast_consume_tokens(t_tok ***token, t_ast *branch, int i)
{
	t_redir	redir;

	redir = NULL;
	while ((**token))
	{
		if ((**token)->type == WORD)
			ast_add_arguments(token, branch, &i);
		else if ((**token)->type == REDIR)
		{
			ast_add_redir(token, &redir);
			(**token) = (**token)->next;
		}
		else
			break ;
	}
	branch->data.redir = redir;
}

static t_ast	*ast_create_left(t_tok ***token, t_ast *branch)
{
	branch = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&branch);
	branch->data.args = (char **)ft_memalloc(sizeof(char *) * 100);
	allocation_check((void *)&branch->data.args);
	branch->type = ast_sniff_for_type((**token));
	ast_consume_tokens(token, branch, 0);
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
	else if ((*token)->type == PIPE)
	{
		(*token) = (*token)->next;
		branch->right = ast_build_tree(token);
	}
	return (branch);
}

t_ast	**ast_constructor(t_shell *shell, t_tok *token)
{
	t_ast	**tree;
	t_tok	*temp;
	int		i;
	int		count;

	i = 0;
	count = count_semicolon(shell->cmd_line);
	temp = token;
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * (count + 1));
	NL;
	while (token)
	{
		ft_printf("tree[%d]: first token: %s\n", i, token->str);
		tree[i] = ast_build_tree(&token);
		if (token && token->type == CHAR_SEMICOLON)
			token = token->next;
		if (!token)
			break ;
		i++;
	}
	tree[i] = NULL;
	token_list_free(temp);
	return (tree);
}

/*
ls -la >>file
tok >
tok >
tok file
tok  ls -la 2&>1 jee
	 la -la > jee 2>&1
	 ls -la > jee .ls
*/
