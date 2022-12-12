/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/12 17:22:26 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	print_zplogo()
{
	ft_putendl(" _____  __      _          _ _");
	ft_putendl("/ __  \\/  |    | |        | | |");
	ft_putendl("   / /  | | ___| |__   ___| | |");
	ft_putendl("  / /   | |/ __|  _ \\ / _ \\ | |");
	ft_putendl(" / /____| |\\__ \\ | | |  __/ | |");
	ft_putendl("\\_____/\\___/___/_| |_|\\___|_|_|");
	ft_putendl("\n		~zraunio & pskytta");
	ft_putchar('\n');
}

static void	print_pzlogo()
{
	ft_putendl(" _____  __      _          _ _");
	ft_putendl("/ __  \\/  |    | |        | | |");
	ft_putendl("   / /  | | ___| |__   ___| | |");
	ft_putendl("  / /   | |/ __|  _ \\ / _ \\ | |");
	ft_putendl(" / /____| |\\__ \\ | | |  __/ | |");
	ft_putendl("\\_____/\\___/___/_| |_|\\___|_|_|");
	ft_putendl("\n		~pskytta & zraunio");
	ft_putchar('\n');
}

static void	print_logo()
{
	int	i;

	srand(time(NULL));
	i = (rand() % 2) + 1;
	ft_printf("\e[1;1H\e[2J");
	if (i == 1)
		print_zplogo();
	else
		print_pzlogo();
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	ft_memset(&shell, EOF, sizeof(shell));
	if (envp)
	{
		init_shell(&shell, envp);
		print_logo();
		ft_print_fd(STDOUT_FILENO, "$> ");
		while (TRUE)
		{
			input_read(&shell);
			if (shell.end == 1)
			{
				t_lex	list;
				ft_memset(&list, 0, sizeof(t_lex));
				lexer(shell.cmd_line, shell.cmd_idx, &list);
				token_list_free(list.token_list);
				ft_memset(shell.cmd_line, '\0', shell.cmd_idx);
				shell.cmd_idx = 0;
			}
		}
	}
	else
		kill_mode("exit", &shell);
	return (EXIT_SUCCESS);
}
