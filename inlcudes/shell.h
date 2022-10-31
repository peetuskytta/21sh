/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/31 16:19:46 by pskytta          ###   ########.fr       */
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
	t_array		*sequence; // array of structs (';' separation)
}	t_shell;

typedef struct s_array
{
	int		type; // populated by PIPE, REDIR, SIMPLE_CMD
}	t_array;


typedef enum t_type
{
	COMMAND,
	PIPE,
	REDIR,
}	e_type;

typedef enum t_state
{
	STATE_START,
	STATE_GENERAL,
	STATE_IN_FILENAME,
	STATE_IN_PIPE,
	STATE_IN_REDIRECT,
	STATE_CMD_SEPARATOR,
}	e_state;

int		env_variable_counter(char **environ);
void	init_shell(t_shell *shell, char **environ);
void	allocation_check(void **check);


# endif
