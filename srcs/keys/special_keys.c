/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:00:36 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 11:04:24 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_escape(t_shell *shell, char *input)
{
	if (input[0] == 27 && input[1] == '\0')
	{
		ft_print_fd(STDOUT_FILENO, "ESCAPE\n");
		return (1);
	}
	else
	{
		shell->dir_len = 0;
		return (0);
	}

}

static int is_arrow(t_shell *shell, char *input)
{
	int	i;

	i = 1;
	if (input[1] == 91 && input[2] == 68 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW LEFT\n");
	else if (input[1] == 91 && input[2] == 67 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW RIGHT\n");
	else if (input[1] == 91 && input[2] == 66 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW DOWN\n");
	else if (input[1] == 91 && input[2] == 65 && input[3] == 0)
		ft_print_fd(STDOUT_FILENO, "ARROW UP\n");
	else
		i = 0;
	shell->dir_len = 0;
	return (i);
}

int	special_keys(t_shell *shell, char *input)
{

	if (input[0] == 27 && !is_arrow(shell, input))
		return (is_escape(shell, input));
	else if (input[0] == ENTER)
	{
		//read_quote(shell);
		goto_newline(shell);
		if (shell->quote == EOF)
			shell->end = 1;
		if (shell->end == 1)
		{
			/*PRINT FOR DEBUGGING PURPOSES*/
			t_lex	list;
			ft_memset((void *)&list, 0, sizeof(list));
			NL;
			ft_putendl(shell->cmd_line);
			lexer(shell->cmd_line, shell->cmd_idx, &list);
			int i = 0;
			NL;
			while (list.token_list != NULL)
			{
				ft_printf("token[%d] type:\t{%d} content:	{%s}\n", i++, list.token_list->type, list.token_list->str);
				list.token_list = list.token_list->next;
			}
			token_list_free(list.token_list);
			ft_memset(shell->cmd_line, '\0', shell->cmd_idx);
			shell->end = 0;
		}
		cmd_line_prompt(shell->quote);
		return (1);
	}
	else
	{
		return (0);
	}
}
