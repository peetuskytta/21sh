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

static t_ast	*ast_create_pipe(int type)
{
	t_ast	*branch;

	branch = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&branch);
	branch->type = type;
	branch->right = NULL;
	branch->left = NULL;
	ft_memset(&branch->data, 0, sizeof(t_data));
	return (branch);
}

static bool	ast_sniff_for_pipe(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp->type != SEPARATOR)
	{
		if (tmp->type == PIPE)
			return (false);
		tmp = tmp->next;
		if (!tmp)
			break ;
	}
	return (true);
}

static int	ast_sniff_for_type(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp->type != SEPARATOR || tmp->type != PIPE)
	{
		tmp = tmp->next;
		if (!tmp)
			return(COMMAND);
	}
	if (tmp->type == REDIR)
		return (REDIR);
	return (COMMAND);
}

static int	ast_word_tok_count(t_tok *token)
{
	t_tok	*tmp;
	int		word_count;

	tmp = token;
	word_count = 1;
	while (tmp->type != SEPARATOR || tmp->type != PIPE)
	{
		if (tmp->type == WORD)
			word_count++;
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
	}
	return (word_count);
}

static t_ast	*ast_create_left(t_tok ***token, t_ast *branch)
{
	int	words;

	words = ast_word_tok_count((**token)->next);
	branch = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&branch);
	branch->data.cmd.args = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	allocation_check((void *)&branch->data.cmd.args);
	ft_memset((void *)&branch->data, 0, sizeof(t_data));
	branch->type = ast_sniff_for_type((**token)->next);

	return (branch);
}

static t_ast	*ast_build_tree(t_tok **token)
{
	t_ast	*branch;

	branch = ast_create_pipe(PIPE);
	branch->left = ast_create_left(&(token), branch);
	if (!(*token) || (*token)->type == SEPARATOR)
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
	int		nbr;

	i = 0;
	nbr = 1;
	nbr += ft_count_chrstr(shell->cmd_line, CHAR_SEMICOLON);
	temp = token;
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * (nbr + 1));
	NL;
	while (token)
	{
		tree[i] = ast_build_tree(&token);
		if (token && token->type == SEPARATOR)
			token = token->next;
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
