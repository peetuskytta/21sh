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

/*static void	token_list_traverse(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == REDIR)
		{
			if (tmp->next)
				tmp->next->type = IO_FILE;
		}
		tmp = tmp->next;
	}
}*/

/*DELETE BEFORE SUBMIT*/
static void	token_list_print(t_tok *token)
{
	t_tok	*temp;
	int i;

	i = 0;
	temp = token;
	NL;
	while (temp != NULL)
	{
		if (temp->str)
			ft_printf("token[%d] type [%d] = %s", i++, temp->type, temp->str);
		temp = temp->next;
		if (temp != NULL)
			NL;
	}
}

t_tok	*parser(t_shell *shell)
{
	t_tok	*temp;
	t_lex	list;

	ft_memset(&list, 0, sizeof(t_lex));
	shell->cmd_idx *= 2;
	if (shell->cmd_idx > 0)
		token_list_build(shell->cmd_line, shell->cmd_idx, &list);
	temp = list.token_list;
	token_list_print(temp);
	return (list.token_list);
}
