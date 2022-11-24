/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/24 17:05:46 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "keys.h"
# include "errors.h"
# include "lexer.h"
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>

// # define EOF '\0'
# define HIST_FILE ".shell_history"

# define TRUE 1
# define FALSE 0
# define BUFFER 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define MAX_BUFF 2049

typedef struct s_exec
{
	char	*cmd;
	char	**args;
}			t_exec;

typedef struct	s_win
{
		struct winsize	*win;
		int				cols;
		int				rows;
		int				current_row;
}				t_win;

typedef struct s_shell
{
	char		**environ;
	int			env_nbr;
	int			env_iflg;
	char		*cmd_line;
	int			quote;
	int			dir_len;
	int			previous_dir_in_cd;
	char		*pwd;
	char		*prev_dir;
	t_win		window;
	struct termios	orig_raw;
	struct termios	raw;
}				t_shell;

/*
** BUILDINS
*/
void	ft_setenv(t_shell *shell, char *args);
int		ft_is_strenv(char *name, char **environ);
void	setenv_update_env(t_shell *shell, char *name, char *value, int i);
void	ft_env(t_shell *shell, char **args);
void	ft_unsetenv(t_shell *shell, char *args);
/*
** SHELL
*/
int		env_variable_counter(char **environ);
void	init_shell(t_shell *shell, char **environ);
void	allocation_check(void **check);
/*
** READ_INPUT
*/
int		command_prompt_loop(t_shell *shell);
char	*handle_open_quotes(t_shell *shell, char *buf, int *quotes);
/*
** PANIC
*/
void	ft_abort(void);
void	ft_perror(const char *s);
char	*ft_strerror(int errnum);
/*
** OUTPUT
*/
int		stdout_char(int c);

/*
** CURSOR
*/
void	init_window(t_win *window);
void	goto_newline(t_shell *shell);
/*
** KEYS
*/
int		ft_iscntrl(char c);
void	keypress(t_shell *shell);
/*
** RAW
*/
int		enable_rawmode(t_shell *shell);
void	kill_mode(const char *str, t_shell *shell);

# endif
