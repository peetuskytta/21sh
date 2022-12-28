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
# include "structs.h"

typedef struct s_fds
{
	int				fd_in;
	int				fd_out;
	int				fd_err;
	int				fd_close;
}					t_fds;

typedef struct s_io
{
	char			in_file[1024];
	char			out_file[1024];
}					t_io;

typedef struct s_redir
{
	struct s_exec	exec;
	struct s_io		io;
	struct s_fds	fds;
}					t_redir;

typedef union s_data
{
	t_redir			redir;
	t_exec			cmd;
}			t_data;

typedef struct s_ast
{
	int				type;
	union s_data	data;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

t_ast	**ast_constructor(t_shell *shell, t_tok *token);
//void	ast_execute(t_ast *root, t_shell *shell);
//void	ast_release(t_ast *root);

# endif
