/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/08 13:50:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	token_initializer(t_tok *tok, size_t size)
{
	tok = (t_tok *)ft_memalloc(size + 1);
	tok->type = CHAR_NULL;
	tok->next = NULL;
}

void	lexer(char *input, size_t size, t_lexer *lex)
{
	t_tok	*token;

	while (ft_isspace(*input))
		input++;
	ft_putendl(input);

	lex->token_list = ft_memalloc(sizeof(t_tok));
	token = lex->token_list;
	token_initializer(token, size);
	// Use function pointers to define what to do when specific char is found.
}
