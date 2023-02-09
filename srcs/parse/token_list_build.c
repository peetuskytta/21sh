/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:15:32 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/09 12:34:32 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static char	get_char_type(char c)
{
	if (c == CHAR_DQUOTE)
		return (CHAR_DQUOTE);
	else if (c == CHAR_ESCAPE)
		return (CHAR_ESCAPE);
	else if (c == CHAR_GREATER)
		return (CHAR_GREATER);
	else if (c == CHAR_LESSER)
		return (CHAR_LESSER);
	else if (c == CHAR_PIPE)
		return (CHAR_PIPE);
	else if (c == CHAR_QUOTE)
		return (CHAR_QUOTE);
	else if (c == CHAR_SEMICOLON)
		return (CHAR_SEMICOLON);
	else if (c == CHAR_WHITESPACE || c == CHAR_TAB)
		return (CHAR_WHITESPACE);
	else
		return (CHAR_GENERAL);
}

static void	token_loop(t_ints st, t_tok *token, char *input, int ch)
{
	while (st.c != NULL_BYTE)
	{
		st.c = input[st.i];
		ch = get_char_type(st.c);
		if (st.state == STATE_GENERAL \
			&& state_general(&st, &token, ch, input) == 1)
			;
		else if (st.state == STATE_REDIR && state_redir(&st, &token) == 1)
			;
		else if ((st.state == STATE_IN_DQUOTE || st.state == STATE_IN_QUOTE \
			|| st.state == STATE_IN_BRACKET) \
			&& state_quotes(&st, &token, ch) == 1)
			;
		else if (ch == CHAR_NULL)
		{
			if (st.t_i > 0)
			{
				token->str[st.t_i] = st.c;
				st.t_i = 0;
			}
		}
		st.i++;
	}
}

void	token_list_build(char *input, int size, t_lex *list)
{
	t_tok	*token;
	t_ints	st;
	int		ch;

	ft_memset(&st, '\0', sizeof(t_ints));
	st.size = size;
	token = NULL;
	ch = -1;
	list->token_list = (t_tok *)ft_memalloc(sizeof(t_tok));
	allocation_check((void *)&list->token_list);
	token = list->token_list;
	init_token(token, size);
	st.c = input[st.i];
	token_loop(st, token, input, ch);
}
