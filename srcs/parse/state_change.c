/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:58:48 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 09:58:48 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	change_state(t_tok *tok, t_ints *st, int ch)
{
	if (tok->type != REDIR)
		tok->type = WORD;
	if (ch == CHAR_DQUOTE)
		st->state = STATE_IN_DQUOTE;
	else if (ch == CHAR_QUOTE)
		st->state = STATE_IN_QUOTE;
	else if (ch == CHAR_ESCAPE)
		st->state = STATE_GENERAL;
	else if (ch == CHAR_BROPEN)
		st->state = STATE_IN_BRACKET;
	else if (ch == CHAR_BROPEN)
		st->state = STATE_GENERAL;
	else if (ch == CHAR_GENERAL)
		st->state = STATE_GENERAL;
	else if (ch == CHAR_GREATER || ch == CHAR_LESSER)
		st->state = STATE_REDIR;
	tok->str[st->t_i] = ch;
	(st->t_i)++;
}
