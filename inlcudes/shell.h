/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/01 21:45:39 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "keys.h"
# include "errors.h"
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <sys/ioctl.h>

#define EOF '\0'
#define HIST_FILE ".shell_history"

#define TRUE 1
#define FALSE 0

typedef struct s_shell
{
	char		*cmd_line;
	char		**env;
}	t_shell;

typedef struct s_exec
{
	char	*cmd;
	char	**args;
}			t_exec;

typedef struct s_pipe
{
	t_exec	cmd;
	char	*file; // in or out file
	int		mode; // depending on '<<' or '>>'
	int		fd; // its 0 or 1 depending on '<' or '>'
}			t_pipe;
typedef struct s_redir
{
	t_exec	cmd;
	char	*file; // in or out file
	int		mode; // O_CREATE etc..
	int		fd;
}			t_redir;
typedef enum t_type
{
	PIPE,
	EXEC,
	REDIR,
}	e_type;
typedef enum t_state
{
	STATE_START,
	STATE_GENERAL,
	STATE_IN_PIPE,
	STATE_IN_FILENAME,
	STATE_IN_REDIRECT,
	STATE_CMD_SEPARATOR,
}	e_state;
typedef union t_command
{
	t_exec	*exec;
	t_redir	*redir;
	t_pipe	*pipe;
}			u_command;

typedef struct s_tree
{
	int			type;
	u_command	*left;
	u_command	*right; // if the last sequence ends set this to NULL to indicate end of tree
}				t_tree;

typedef struct	s_win
{
		struct winsize	*win;
		int				cols;
		int				rows;
		int				current_row;
}				t_win;

typedef struct s_shell
{
	char	**environ;
	char	*minish;
	int		num_of_variables;
	int		quote;
	int		dir_len;
	int		previous_dir_in_cd;
	char	*prev_dir;
	t_win	*window;
}				t_shell;

/*
** SHELL
*/
int		env_variable_counter(char **environ);
void	init_shell(t_shell *shell, char **environ);
void	allocation_check(void **check);
/*
** CURSOR
*/
void	init_window(t_win *window);
/*
** KEYS
*/
int		ft_iscntrl(char c);
void	keypress(void);
/*
** RAW
*/
int		enable_rawmode(void);
void	kill_mode(const char *str);

# endif
