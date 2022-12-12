/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:06 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/12 13:05:08 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSE_H
# define PARSE_H
# include "shell.h"
# include "structs.h"

typedef enum e_tok_type
{
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
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

typedef enum e_state
{
	STATE_IN_DQUOTE,
	STATE_IN_SQUOTE,
	STATE_IN_ESCAPE,
	STATE_GENERAL,
}	t_state;

typedef struct s_tok
{
	int				type;
	char			*word;
	struct s_tok	*next;
}			t_tok;

typedef struct s_lexer
{
	t_tok	*token_list;
	size_t	elements;
}			t_lexer;

void	lexer(char *input, size_t size, t_lexer *lex);

# endif
