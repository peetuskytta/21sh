/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:22:21 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/14 11:22:21 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	parsing(t_shell *shell)
{
	t_lex	list;

	//ft_putendl(shell.cmd_line);
	ft_memset(&list, 0, sizeof(t_lex));
	lexer(shell->cmd_line, shell->cmd_idx, &list);
	//token_list_free(list->token_list);
	ft_memset(shell->cmd_line, '\0', ft_strlen(shell->cmd_line));
	shell->cmd_idx = 0;
	shell->end = 0;
}
