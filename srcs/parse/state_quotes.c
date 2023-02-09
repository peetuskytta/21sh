/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:02:59 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 10:02:59 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	state_quotes(t_ints *st, t_tok **token, int ch_type)
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
	else if (st->state == STATE_IN_BRACKET)
	{
		(*token)->str[st->t_i++] = st->c;
		if (st->c == CHAR_BRCLOSE)
			st->state = STATE_GENERAL;
	}
	return (1);
}
