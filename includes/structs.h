/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:45:34 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/16 14:15:35 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCTS_H
# define STRUCTS_H
# include "shell.h"
# include <termios.h>

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

typedef struct s_exec
{
	char	*cmd;
	char	**args;
}			t_exec;

# endif
