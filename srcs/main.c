/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/15 09:49:18 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	ft_memset(&shell, 0, sizeof(t_shell));
	if (envp)
	{
		init_shell(&shell, envp);
		ft_print_fd(STDOUT_FILENO, "$> ");
		while (TRUE)
		{
			input_read(&shell);
			if (shell.end == 1 && shell.quote == EOF)
			{
				parsing(&shell);
				/*
				PUT THE BELOW IN SEPARATE ast FOLDER:
					ast_build();
					ast_exectute();
					ast_destroy();
				*/
			}
		}
	}
	else
		kill_mode("exit", &shell);
	return (EXIT_SUCCESS);
}
