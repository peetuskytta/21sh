/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:45:34 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/10 09:06:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "shell.h"
# include <termios.h>
# define MAX_REDIR 512
# define MAX_PIPE 700

typedef struct s_termcaps
{
	char	*buff_area;
	char	*term_ti_start;
	char	*term_te_stop;
	char	*term_cl_clear_screen;
	char	*term_ce_clear_end_of_line;
	char	*term_cm_cursor_pos;
	int		cursor_y;
	int		cursor_x;
	int		start_cursor_y;
	int		start_cursor_x;
}			t_termcaps;

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
	int				flg;
	char			*history[1001];
	int				history_line;
	int				history_len;
	int				history_out;
	int				hist_idx;
	char			*q_input;
	char			input[1024][MAX_REDIR];
	char			tmp_str[1024];
	char			found_command[1024];
	int				found_command_index;
	char			*cmd_line;
	char			*rev_cmd;
	char			*temp;
	char			*clipbrd;
	char			*cwd;
	int				fd_out;
	int				fd_in;
	int				fd_err;
	int				input_len;
	int				input_rows;
	int				cmd_idx;
	int				prmpt_len;
	char			prompt[MAX_REDIR + 31];
	int				reverse_search;
	int				reverse_delete;
	int				middle;
	int				window_rows;
	int				window_columns;
	int				end;
	int				quote;
	int				pid_i;
	int				pid_check;
	pid_t			pid;
	pid_t			child;
	bool			pipe;
	int				pipe_err;
	char			*tty;
	bool			last_io;
	t_termcaps		tcaps;
	t_win			window;
	struct termios	orig_t;
	struct termios	raw_t;
	int				raw;
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
	int				fd_err;
	int				agre;
	char			*file_in;
	char			*file;
}					t_redir;

typedef struct s_pid
{
	int				child;
	int				wait;
	int				status;
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
	int				agre;
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

typedef struct s_herfd
{
	int		fd;
	int		idx;
	int		end;
	int		cols;
	char	*input;
	char	*delim;
}				t_herfd;

typedef struct s_ints
{
	char	c;
	int		i;
	int		t_i;
	int		size;
	int		state;
}				t_ints;

#endif
