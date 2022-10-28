/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/28 14:35:55 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "keys.h"


#define EOF '\0'

typedef struct s_shell
{
	char	*cmd_line;
}	t_shell;

typedef struct s_cmd
{
	int	type;
}	t_cmd;

typedef struct s_exec
{
	int		type;
	char	**arg_start;
	char	**arg_end;
}	t_exec;

typedef struct s_redir
{
	int		type;
	t_cmd	*command;
	char	*f_start;
	char	*f_end;
	int		mode;
	int		fd;
}	t_redir;

typedef struct s_pipe
{
	int		type;
	t_cmd	*left;
	t_cmd	*right;
}	t_pipe;







typedef enum t_state
{
	STATE_START,
	STATE_GENERAL,
	STATE_IN_FILENAME,
	STATE_IN_PIPE,
	STATE_IN_REDIRECT,
	STATE_CMD_SEPARATOR,
}	e_state;

typedef enum t_char_category
{
	CHAR_GENERAL,
	CHAR_WHITESPACE = ' ',
	CHAR_PIPE = '|',
	CHAR_EOF = EOF,
	CHAR_IOR,
}	e_category;


# endif
