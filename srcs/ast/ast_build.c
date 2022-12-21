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
	ft_memset(&branch->command, 0, sizeof(t_pipe));
	return (branch);
}

static t_ast	*ast_create_command(int type, t_tok ***token, t_ast *branch)
{
	branch = (t_ast *)ft_memalloc(sizeof(t_ast));
	allocation_check((void *)&branch);
	branch->command.exec.args = (char **)ft_memalloc(sizeof(char *) * 100);
	allocation_check((void *)&branch->command.exec.args);
	ft_memset((void *)branch->command.exec.args, 0, 100);
	branch->type = type;
	int i = 0;
	while (**token)
	{
		if ((**token)->type == WORD)
		{
			branch->command.exec.args[i++] = ft_strdup((**token)->str);
			(**token) = (**token)->next;
		}
		else
			break;
	}
	branch->command.exec.args[i] = NULL;
	return (branch);
}

static bool	ast_sniff_next(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp)
	{
		if (token->type == PIPE)
			return (false);
		if (token->type == SEPARATOR)
			break ;
		tmp = tmp->next;
	}
	return (true);
}

static t_ast	*ast_build_branches(t_tok **token)
{
	t_ast	*branch;

	branch = ast_create_pipe(PIPE);
	branch->left = ast_create_command(COMMAND, &(token), branch);
	if (!(*token) || (*token)->type == SEPARATOR)
		return (branch);
	if (ast_sniff_next((*token)->next))
	{
		(*token) = (*token)->next;
		branch->right = ast_create_command(COMMAND, &(token), branch);
	}
	else if ((*token)->type == PIPE)
	{
		(*token) = (*token)->next;
		branch->right = ast_build_branches(token);
	}
	return (branch);
}

t_ast	**ast_build(t_shell *shell, t_tok *token)
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
	int ii = 0;
	NL;
	while (token)
	{
		tree[i] = ast_build_branches(&token);
		NL;
		ft_printf("tree[%d]\n", i);
		if (tree[i]->right->type == COMMAND || tree[i]->right->type == PIPE)
		{
			while (tree[i]->right->command.exec.args[ii])
			{
				ft_printf("\targs[%d] = %s\n", ii, tree[i]->right->command.exec.args[ii]);
				ii++;
			}
		}
		else if (tree[i]->left->type == COMMAND)
		{
			while (tree[i]->left->command.exec.args[ii])
			{
				DB;
				ft_printf("\targs[%d] = %s\n", ii, tree[i]->left->command.exec.args[ii]);
				ii++;
			}
		}
		if (token && token->type == SEPARATOR)
			token = token->next;
		ii = 0;
		i++;
	}
	tree[i] = NULL;
	token_list_free(temp);
	//ft_putendl(tree[0]->left->command.exec.args[0]);
	//exit(111);
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
