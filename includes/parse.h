/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:06 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/09 12:30:54 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "shell.h"

typedef enum e_tok_type
{
	CHAR_PIPE = '|',
	CHAR_BROPEN = '{',
	CHAR_BRCLOSE = '}',
	CHAR_QUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_WHITESPACE = ' ',
	CHAR_AMPERSAND = '&',
	CHAR_TILDE = '~',
	CHAR_DOLLAR = '$',
	CHAR_ESCAPE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_GENERAL = -1,
	CHAR_NULL = 0,
	TOKEN = -1,
}	t_tok_type;

typedef enum e_type
{
	COMMAND,
	PIPE,
	REDIR,
	SEPARATOR,
	WORD,
}	t_type;

typedef enum e_red
{
	FILE_IN = 2,
	FILE_OUT = 3,
	FILE_APPEND = 5,
	FILE_TRUNC = 6,
	FILE_INVALID = 7,
	FILE_PARSE_ERR = 8,
	ERR_ON = 9,
}	t_red;

typedef enum e_aggr
{
	AGGR_CLOSE_BOTH = 10,
	AGGR_CLOSE_ONE = 11,
	AGGR_CLOSE_TWO = 12,
	AGGR_COPY_ONE = 13,
	AGGR_COPY_TWO = 14,
	AGGR_COPY_BOTH = 15,
}	t_aggr;

typedef enum e_state
{
	STATE_GENERAL,
	STATE_REDIR,
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPE,
	STATE_IN_BRACKET,
}	t_state;

t_tok	*parser(t_shell *shell);
int		state_redir(t_ints *st, t_tok **token);
int		state_general(t_ints *st, t_tok **token, int ch_type, char *input);
int		state_quotes(t_ints *st, t_tok **token, int ch_type);
void	change_state(t_tok *tok, t_ints *st, int ch);
void	init_token(t_tok *token, int size);
void	token_list_build(char *input, int size, t_lex *list);
void	token_list_free(t_tok *list);
void	parse_errors(t_tok **first);
bool	parse_redir_errors(char *str, t_tok *next);
bool	separator_checks(t_tok **tok);
bool	redir_checks(t_tok *tok);
bool	run_parser_checks(t_tok *first);

#endif
