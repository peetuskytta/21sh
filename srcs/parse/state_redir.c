/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:50:11 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 09:50:11 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	state_redir(t_ints *st, t_tok **token)
{
	if (!ft_strchr("&><-12", st->c))
	{
		(*token)->type = REDIR;
		(*token)->next = (t_tok *)ft_memalloc(sizeof(t_tok));
		allocation_check((void *)(*token)->next);
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
