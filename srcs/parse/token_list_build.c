/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:15:32 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/30 16:52:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void	init_token(t_tok *token, int size)
{
	token->str = (char *)ft_memalloc(sizeof(char) * size + 1);
	allocation_check((void *)(token->str));
	ft_memset(token->str, NULL_BYTE, size + 1);
	token->type = CHAR_NULL;
	token->next = NULL;
}

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

static void	change_state(t_tok *tok, t_ints *st, int ch)
{
	if (tok->type != REDIR)
		tok->type = WORD;
	if (ch == CHAR_DQUOTE)
		st->state = STATE_IN_DQUOTE;
	else if (ch == CHAR_QUOTE)
		st->state = STATE_IN_QUOTE;
	else if (ch == CHAR_ESCAPE)
		st->state = STATE_GENERAL;
	else if (ch == CHAR_GENERAL)
		st->state = STATE_GENERAL;
	else if (ch == CHAR_GREATER || ch == CHAR_LESSER)
		st->state = STATE_REDIR;
	tok->str[st->t_i] = ch;
	(st->t_i)++;
}

static int	state_general(t_ints *st, t_tok **token, int ch_type, char *input)
{
	if (ch_type == CHAR_QUOTE)
		change_state(*token, st, CHAR_QUOTE);
	else if (ch_type == CHAR_DQUOTE)
		change_state(*token, st, CHAR_DQUOTE);
	else if (ch_type == CHAR_GREATER || ch_type == CHAR_LESSER
		|| ch_type == CHAR_GENERAL)
		change_state(*token, st, st->c);
	else if (ch_type == CHAR_ESCAPE)
		change_state(*token, st, input[++st->i]);
	else if (ch_type == CHAR_WHITESPACE)
	{
		if (st->t_i > 0 && input[st->i + 1] != CHAR_WHITESPACE
			&& input[st->i + 1] != CHAR_TAB)
		{
			(*token)->str[st->t_i] = NULL_BYTE;
			if (input[st->i + 1] == NULL_BYTE)
				return (0);
			(*token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
			*token = (*token)->next;
			init_token(*token, st->size - st->i);
			st->t_i = 0;
		}
	}
	else if (ch_type == CHAR_SEMICOLON || ch_type == CHAR_PIPE)
	{
		if (st->t_i > 0)
		{
			(*token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
			*token = (*token)->next;
			init_token(*token, st->size - st->i);
			st->t_i = 0;
		}
		if (st->t_i == 0 && input[st->i + 1] == NULL_BYTE)
			return (0);
		(*token)->str[0] = ch_type;
		(*token)->str[1] = NULL_BYTE;
		(*token)->type = ch_type;
		(*token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
		*token = (*token)->next;
		init_token(*token, st->size - st->i);
	}
	return (1);
}

static int	state_redir(t_ints *st, t_tok **token)
{
	if (!ft_strchr("&><-12", st->c))
	{
		(*token)->type = REDIR;
		(*token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
		*token = (*token)->next;
		init_token(*token, st->size - st->i);
		(*token)->type = REDIR;
		st->state = STATE_GENERAL;
		st->t_i = 0;
	}
	if (st->c != CHAR_WHITESPACE)
	{
		(*token)->type = REDIR;
		(*token)->str[st->t_i++] = st->c;
	}
	return (1);
}

static int	state_quotes(t_ints *st, t_tok **token, int ch_type)
{
	if (st->state == STATE_IN_DQUOTE)
	{
		(*token)->str[st->t_i++] = st->c;
		if (st->c == CHAR_GREATER || st->c == CHAR_LESSER)
			(*token)->type = REDIR;
		if (ch_type == CHAR_DQUOTE)
			st->state = STATE_GENERAL;
	}
	else if (st->state == STATE_IN_QUOTE)
	{
		(*token)->str[st->t_i++] = st->c;
		if (st->c == CHAR_GREATER || st->c == CHAR_LESSER)
			(*token)->type = REDIR;
		if (ch_type == CHAR_QUOTE)
			st->state = STATE_GENERAL;
	}
	return (1);
}

void	token_list_build(char *input, int size, t_lex *list)
{
	t_tok	*token;
	char	ch_type;
	t_ints	st;

	ft_memset(&st, '\0', sizeof(t_ints));
	st.size = size;
	token = NULL;
	list->token_list = (t_tok *)ft_memalloc(sizeof(t_tok));
	token = list->token_list;
	init_token(token, size);
	st.c = input[st.i];
	while (st.c != NULL_BYTE)
	{
		st.c = input[st.i];
		ch_type = get_char_type(st.c);
		if (st.state == STATE_GENERAL && state_general(&st, &token, ch_type, input) == 1)
			;
		else if (st.state == STATE_REDIR && state_redir(&st, &token) == 1)
			;
		else if ((st.state == STATE_IN_DQUOTE || st.state == STATE_IN_QUOTE) && \
			state_quotes(&st, &token, ch_type) == 1)
			;
		else if (ch_type == CHAR_NULL)
		{
			if (st.t_i > 0)
			{
				token->str[st.t_i] = NULL_BYTE;
				st.t_i = 0;
			}
		}
		st.i++;
	}
}
