/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/14 08:59:55 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	ft_memset(&shell, 0, sizeof(shell));
	if (envp)
	{
		init_shell(&shell, envp);
		ft_print_fd(STDOUT_FILENO, "$> ");
		while (TRUE)
		{
			input_read(&shell);
			if (shell.end == 1 && shell.quote == EOF)
			{
				t_lex	list;
				//ft_putendl(shell.cmd_line);
				ft_memset(&list, 0, sizeof(t_lex));
				lexer(shell.cmd_line, shell.cmd_idx, &list);
				//token_list_free(list.token_list);
				ft_memset(shell.cmd_line, '\0', ft_strlen(shell.cmd_line));
				shell.cmd_idx = 0;
				shell.end = 0;
			}
		}
	}
	else
		kill_mode("exit", &shell);
	return (EXIT_SUCCESS);
}
