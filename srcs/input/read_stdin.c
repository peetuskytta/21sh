/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:14 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/11 23:43:21 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void free_list(t_tok *list)
{
	t_tok	*temp;
	t_tok	*store;

	temp = list;
	while (temp != NULL)
	{
		store = temp->next;
		ft_strdel(&temp->str);
		ft_memdel((void *)&temp);
		temp = store;
		free(temp);
	}
	list = NULL;
}

void read_stdin(t_shell *shell)
{
	char	input[MAX_BUFF + 1];
	t_lex	list;

	write(1, "$> ", 4);
	while (TRUE)
	{
		if (enable_rawmode(shell) == 0)
			ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
		init_window(&shell->window);
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
		read_key(shell, input);
		tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);

		/*PRINT FOR DEBUGGING PURPOSES*/
		if (shell->end == 1)
		{
			lexer(shell->cmd_line, shell->cmd_idx, &list);
			int i = 0;
			while (list.token_list != NULL)
			{
				ft_printf("token[%d]type:\t{%d} content: {%s}\n", i, list.token_list->type, list.token_list->str);
				i++;
				list.token_list = list.token_list->next;
			}
			free_list(list.token_list);
		}
	}
	kill_mode("exit", shell);
}
