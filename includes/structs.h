/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:45:34 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/02 09:46:52 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCTS_H
# define STRUCTS_H
# include "shell.h"
# include <termios.h>

# define MAX_REDIR 512

typedef struct	s_win
{
	struct winsize	*win;
	int				cols;
	int				rows;
	int				current_row;
}					t_win;

typedef struct s_shell
{
	char		**environ;
	int			env_nbr;
	int			env_iflg;
	char		*history[1001];
	int			hist_idx;
	char		*cmd_line;
	char		*rev_cmd;
	int			cmd_idx;
	int			end;
	int			quote;
	int			q_count;
	char		*tty;
	t_win		window;
	struct termios	orig_raw;
	struct termios	raw;
}				t_shell;

typedef struct s_fds
{
	int			fd_in;
	int			fd_out;
	int			fd_err;
	int			fd_closed;
}				t_fds;

typedef struct s_redir
{
	int				type;
	int				fildes;
	int				aggr;
	char			*file;
}					t_redir;

typedef struct s_exec
{
	char			*cmd;
	char			*args[MAX_REDIR];
	struct s_redir	redir[MAX_REDIR];
	struct s_fds	fds;
}					t_exec;

typedef struct s_tok
{
	int				type;
	char			*str;
	struct s_tok	*next;
}					t_tok;

typedef struct s_lex
{
	t_tok	*token_list;
}			t_lex;

typedef struct s_ast
{
	int				type;
	struct s_exec	data;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

# endif
