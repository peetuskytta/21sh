/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:15:37 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 17:15:37 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_tok	*parser(t_shell *shell, t_lex *list)
{
	t_tok	*head;

	ft_memset(list, 0, sizeof(t_lex));
	lexer(shell->cmd_line, shell->cmd_idx, list);
	head = list->token_list;
	int i = 0;
	NL;
	while (list->token_list != NULL)
	{
		if (list->token_list->str)
			ft_printf("token[%d] type [%d] = %s", i++, list->token_list->type, list->token_list->str);
		list->token_list = list->token_list->next;
		NL;
	}
	//ast_tree(head, shell);
	//token_list_free(head);
	return (head);
}
