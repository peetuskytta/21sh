/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:50:37 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 09:50:37 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	init_token(t_tok *token, int size)
{
	token->str = (char *)ft_memalloc(sizeof(char) * size + 1);
	allocation_check((void *)(token->str));
	ft_memset(token->str, NULL_BYTE, size + 1);
	token->type = CHAR_NULL;
	token->next = NULL;
}
