/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:45:34 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 16:19:29 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "shell.h"
# include <termios.h>
# define MAX_REDIR 512
# define MAX_PIPE 700

typedef struct s_win
{
	struct winsize	*win;
	int				cols;
	int				rows;
	int				current_row;
	char			*row_idx[4096];
	int				idx;
	int				loc;
}					t_win;

typedef struct s_shell
{
	char			**environ;
	int				stdout_fd;
	int				env_nbr;
	int				flg;
	char			*history[1001];
	int				hist_idx;
	char			*q_input;
	char			*input;
	char			*cmd_line;
	char			*rev_cmd;
	char			*temp;
	char			*clipbrd;
	int				cmd_idx;
	int				prmpt_len;
	int				end;
	int				quote;
	char			*tty;
	bool			last_io;
	pid_t			child;
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
	int				heredoc;
}					t_fds;

typedef struct s_redir
{
	int				type;
	int				fd_in;
	int				fd_out;
	char			*file;
}					t_redir;

typedef struct s_pid
{
	int				child;
	int				wait;
	pid_t			status;
}					t_pid;

typedef struct s_exec
{
	char			*cmd;
	char			*args[MAX_REDIR];
	struct s_redir	redir[MAX_REDIR];
	struct s_fds	fds;
	struct s_pid	pid;
	int				process_pid;
	int				status;
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

#endif

// ls -l | grep file | wc -l
// ls -lRl | grep Makefile | cat -e ; ps aux | grep
// ls -R | grep Makefile | cat -e ; ps -j
// ls -R / | grep Makefile | cat -e ; ps -j
