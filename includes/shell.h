/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/17 15:07:39 by pskytta          ###   ########.fr       */
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

# define HIST_FILE ".shell_history"

# define TRUE 1
# define FALSE 0
# define BUFFER 1024
# define S_QUOTE '\''
# define D_QUOTE '\"'

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
	char		*cmd_line;
	char		*minish;
	int			num_of_variables;
	int			quote;
	int			dir_len;
	int			previous_dir_in_cd;
	char		*prev_dir;
	t_win		*window;
	struct termios	orig_raw;
	struct termios	raw;
}				t_shell;

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
** CURSOR
*/
void	init_window(t_win *window);
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

#define HIST_FILE ".shell_history"

#define NULL_BYTE '\0'
#define TRUE 1
#define FALSE 0

int		env_variable_counter(char **environ);
void	init_shell(t_shell *shell, char **environ);
void	allocation_check(void **check);


# endif
