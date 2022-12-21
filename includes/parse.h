/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:06 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/21 09:04:13 by pskytta          ###   ########.fr       */
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
	STATE_REDIR,
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_ESCAPE,
}	e_state;

void	token_list_build(char *input, int size, t_lex *list);
void	token_list_free(t_tok *list);
t_tok	*parser(t_shell *shell);

# endif
