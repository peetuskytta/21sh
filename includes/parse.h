/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:06 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/29 17:36:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "shell.h"

typedef enum e_tok_type
{
	CHAR_PIPE = '|',
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
}	t_state;

void	token_list_build(char *input, int size, t_lex *list);
void	token_list_free(t_tok *list);
t_tok	*parser(t_shell *shell);
void	parse_errors(t_tok **first);
bool	parse_redir_errors(char *str, t_tok *next);

#endif
