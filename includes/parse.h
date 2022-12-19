/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:06 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/16 16:32:20 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "shell.h"
# include "structs.h"

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
	WORD,
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
	int				type;
	char			*str;
	//struct s_tok	*previous;
	struct s_tok	*next;
}					t_tok;

typedef struct s_lex
{
	t_tok	*token_list;
}			t_lex;

typedef struct s_simple_cmd
{
	char	*cmd;
	char	**arguments;
}			t_simple_cmd;

typedef struct s_redir_cmd
{
	char	*cmd;
	char	**arguments;
}			t_redir_cmd;

typedef struct s_redir
{
	char	*cmd;
	char	**arguments;
	char	*file_in;
	char	*file_out;
	int		fd[2];
}			t_redir;

typedef union u_cmd
{
	t_simple_cmd	*cmd;
	t_redir			*redir;
}					t_cmd;

typedef struct s_ast_node
{
	int					type;
	union u_cmd			*cmd;
	struct s_ast_node	*next;
	struct s_ast_node	*previous;
}						t_ast_node;

typedef struct s_ast
{
	t_ast_node	*node;
}				t_ast;

void	lexer(char *input, int size, t_lex *list);
void	token_list_free(t_tok *list);
void	parsing(t_shell *shell);

# endif
