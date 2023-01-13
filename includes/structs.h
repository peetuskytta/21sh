/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:45:34 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/13 08:51:43 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "shell.h"
# include <termios.h>

# define MAX_REDIR 512

typedef struct s_win
{
	struct winsize	*win;
	int				cols;
	int				rows;
	int				current_row;
	int				row_idx[4096];
	int				rows_q;
	int				loc;
}					t_win;

typedef struct s_shell
{
	char			**environ;
	int				stdout_fd;
	int				env_nbr;
	int				env_iflg;
	char			*history[1001];
	int				hist_idx;
	char			*temp;
	char			*cmd_line;
	char			*rev_cmd;
	int				cmd_idx;
	int				prmpt_len;
	int				end;
	int				quote;
	char			*tty;
	t_win			window;
	struct termios	orig_raw;
	struct termios	raw;
}					t_shell;

typedef struct s_fds
{
	int				fd_in;
	int				fd_out;
	int				fd_err;
	int				fd_close;
	int				pipe;
}					t_fds;

typedef struct s_file
{
	int				type;
	int				file_fd;
	char			*file;
}					t_file;

typedef struct s_redir
{
	struct s_file	file_in;
	struct s_file	file_out;
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
	t_tok			*token_list;
}					t_lex;

typedef struct s_pipe
{
	int				fd[2];
}					t_pipe;

typedef struct s_ast
{
	int				type;
	struct s_exec	data;
	struct s_ast	*left;
	struct s_ast	*right;
	struct s_pipe	pipes[MAX_REDIR];
}					t_ast;

typedef struct s_pid
{
	int				child;
	int				wait;
	int				status;
}					t_pid;

#endif

// ls -l | grep file | wc -l