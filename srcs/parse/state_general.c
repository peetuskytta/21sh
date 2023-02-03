/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:53:24 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 09:53:24 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static int	handle_ws(t_ints *st, t_tok ***token, int ch_type, char *input)
{
	if (ch_type == CHAR_WHITESPACE)
	{
		if (st->t_i > 0 && input[st->i + 1] != CHAR_WHITESPACE
			&& input[st->i + 1] != CHAR_TAB)
		{
			(**token)->str[st->t_i] = NULL_BYTE;
			if (input[st->i + 1] == NULL_BYTE)
				return (0);
			(**token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
			**token = (**token)->next;
			init_token((**token), st->size - st->i);
			st->t_i = 0;
		}
	}
	return (1);
}

static int	handle_separators(t_ints *st, t_tok ***token, int ch, char *input)
{
	(void)input;
	if (ch == CHAR_SEMICOLON || ch == CHAR_PIPE)
	{
		if (st->t_i > 0)
		{
			(**token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
			**token = (**token)->next;
			init_token((**token), st->size - st->i);
			st->t_i = 0;
		}
		(**token)->str[0] = ch;
		(**token)->str[1] = NULL_BYTE;
		(**token)->type = ch;
		(**token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
		**token = (**token)->next;
		init_token((**token), st->size - st->i);
	}
	return (1);
}

int	state_general(t_ints *st, t_tok **token, int ch_type, char *input)
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
	else if (handle_ws(st, &token, ch_type, input) == 0)
		return (0);
	else if (handle_separators(st, &token, ch_type, input))
		{};
	return (1);
}
