/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:06 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/08 12:08:22 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "shell.h"

typedef enum e_tok_type
{
	CHAR_PIPE = '|',
	CHAR_QUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_WHITESPACE = ' ',
	CHAR_ESCAPE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_GENERAL = -1,
	CHAR_NULL = 0,
	TOKEN = -1,
}	t_tok_type;

typedef enum t_type
{
	COMMAND,
	PIPE,
	REDIR,
	SEPARATOR,
}	e_type;

typedef enum t_state
{
	STATE_GENERAL,
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPE,
}	e_state;

typedef struct s_tok
{
	int		type;
	char	string[1024];
}			t_tok;

typedef struct s_simple
{
	char	*cmd;
	char	**args;
	char	**envp;
}			t_simple;

typedef struct s_redir
{
	char	*cmd;
	char	**args;
	char	**envp;
	char	*in_file;
	char	*out_file;
}			t_redir;

typedef struct s_pipe
{
	char	*cmd;
	char	**args;
	char	**envp;
	int		fd[2];
}			t_pipe;

typedef union u_cmd
{
	int			type;
	t_simple	*simple;
	t_redir		*redir;
	t_pipe		*pipe;
}				t_cmd;

typedef struct s_jobs
{
	union u_cmd	*cmd;
}				t_jobs;

void	lexer(char *input);

#endif