/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:47:26 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 14:47:26 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include "shell.h"

typedef struct s_ast
{
	int				type;
	struct s_exec	data;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

t_ast	**ast_constructor(t_shell *shell, t_tok *token);
void	ast_consume_tokens(t_tok ***token, t_ast *branch, int i);
void	ast_set_redir(t_redir *redir, char *str);
//void	ast_release(t_ast *root);

/*DELETE BEFORE SUBMIT*/
void	ast_print(t_ast *tree);

# endif
