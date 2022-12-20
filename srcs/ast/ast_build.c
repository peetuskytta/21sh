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
	//ft_memset((void *)&branch, 0, sizeof(t_ast));
	branch->type = type;
	return (branch);
}

static t_ast	*ast_create_command(int type, t_tok ***token)
{
	t_ast	*command;

	command = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&command);
	//ft_memset((void *)&command, 0, sizeof(t_ast));
	command->commands.exec.args = (char **)ft_memalloc(sizeof(char *) * 10);
	allocation_check((void *)&command->commands.exec.args);
	command->type = type;
	int i = 0;
	while (**token)
	{
		if ((**token)->type == WORD)
		{
			command->commands.exec.args[i++] = ft_strdup((**token)->str);
			(**token) = (**token)->next;
		}
	}
	command->commands.exec.args[i] = NULL;
	DB;
	return (command);
}

static t_ast	*ast_build_branches(t_tok **token)
{
	t_ast	*branches;

	branches = ast_create_pipe(PIPE);
	branches->left = ast_create_command(COMMAND, &(token));
	if (!(*token) || (*token)->type == SEPARATOR)
		return (branches);
	else if ((*token)->type == PIPE)
	{
		(*token) = (*token)->next;
		branches->right = ast_build_branches(token);
	}
	return (branches);
}

t_ast	**ast_build(t_shell *shell, t_tok *token)
{
	t_ast	**tree;
	t_tok	*temp;
	int		i;

	i = 0;
	temp = token;
	tree = (t_ast **)ft_memalloc(sizeof(t_ast *) * ft_count_chrstr(shell->cmd_line, CHAR_SEMICOLON) + 1);
	//ft_memset((void *)&tree, 0, sizeof(t_ast));
	while (token)
	{
		tree[i] = ast_build_branches(&token);
		ft_putendl(tree[i]->commands.exec.args[0]);
		ft_putendl(tree[i]->commands.exec.args[1]);
		if (token->type == SEPARATOR && token)
			token = token->next;
		i++;
	}
	tree[i] = NULL;
	token_list_free(temp);
	//ft_putendl(tree[0]->left->commands.exec.args[0]);
	//exit(111);
	return (tree);
}