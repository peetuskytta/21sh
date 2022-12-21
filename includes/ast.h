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

typedef struct s_fds
{
	int				fd_in;
	int				fd_out;
	int				fd_err;
	int				fd_close;
}					t_fds;

typedef struct s_redir
{
	char			*file_in;
	char			*file_out;
}					t_redir;

typedef struct s_pipe
{
	struct s_exec	exec;
	struct s_redir	redir;
	struct s_fds	fds;
}					t_pipe;

typedef union s_cmd
{
	t_pipe	*pipe;
	
}			t_cmd;

typedef struct s_ast
{
	int				type;
	struct s_pipe	command;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

t_ast	**ast_build(t_shell *shell, t_tok *token);
//void	ast_execute(t_ast *root, t_shell *shell);
//void	ast_release(t_ast *root);

# endif
