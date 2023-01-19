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

/*DELETE BEFORE SUBMIT*/
// void	token_list_print(t_tok *token)
// {
// 	t_tok	*temp;
// 	int		i;

// 	i = 0;
// 	temp = token;
// 	NL;
// 	while (temp != NULL)
// 	{
// 		if (temp->str)
// 			ft_printf("token[%d] type [%d] = %s", i++, temp->type, temp->str);
// 		temp = temp->next;
// 		if (temp != NULL)
// 			NL;
// 	}
// 	if (temp == NULL)
// 		ft_printf("\ntoken[%d] (NULL)\n", i);
// }

t_tok	*parser(t_shell *shell)
{
	t_lex	list;

	ft_memset(&list, 0, sizeof(t_lex));
	shell->cmd_idx *= 2;
	if (shell->cmd_idx > 0)
		token_list_build(shell->cmd_line, shell->cmd_idx, &list);
	parse_errors(&list.token_list);
	return (list.token_list);
}
	// t_tok	*temp = list.token_list;
	// token_list_print(temp);

// 2>&1 ---> redirect STDERR to STDOUT, redirects it to the same location
// 1>&2 ---> redirect STDOUT to STDERR, redirects it to the same location

// 0>&- = closes the STDIN
// 1>&- = closes the STDOUT
// 2>&- = closes the STDERR