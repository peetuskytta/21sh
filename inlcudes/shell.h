/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/01 17:56:02 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHELL_H
# define SHELL_H
# include "../libft/incl/libft.h"
# include "keys.h"

#define EOF '\0'
#define HIST_FILE ".shell_history"

#define TRUE 1
#define FALSE 0

typedef struct s_shell
{
	char		*cmd_line;
	char		**env;
}	t_shell;

typedef struct s_simple_cmd
{
	char	*cmd;
	char	**args;
}	t_simple_cmd;

typedef struct s_redir
{
	t_simple_cmd	cmd;
	char			*file; // in or out file
	int				mode; // O_CREATE etc..
	int				fd;
}	t_redir;

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
	t_simple_cmd	cmd;
	t_redir			redir;
	t_pipe			pipe;
}	u_command;

typedef struct s_tree
{
	int			type;
	u_command	*left;
	u_command	*right; // if the last sequence ends set this to NULL to indicate end of tree
}				t_tree;

int		env_variable_counter(char **environ);
void	init_shell(t_shell *shell, char **environ);
void	allocation_check(void **check);

# endif
