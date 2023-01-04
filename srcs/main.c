/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/04 14:50:01 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	print_zplogo()
{
	ft_putendl_fd(" _____  __      _          _ _", STDIN_FILENO);
	ft_putendl_fd("/ __  \\/  |    | |        | | |", STDIN_FILENO);
	ft_putendl_fd("   / /  | | ___| |__   ___| | |", STDIN_FILENO);
	ft_putendl_fd("  / /   | |/ __|  _ \\ / _ \\ | |", STDIN_FILENO);
	ft_putendl_fd(" / /____| |\\__ \\ | | |  __/ | |", STDIN_FILENO);
	ft_putendl_fd("\\_____/\\___/___/_| |_|\\___|_|_|", STDIN_FILENO);
	ft_putendl_fd("\n		~zraunio & pskytta", STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
}

static void	print_pzlogo()
{
	ft_putendl_fd(" _____  __      _          _ _", STDIN_FILENO);
	ft_putendl_fd("/ __  \\/  |    | |        | | |", STDIN_FILENO);
	ft_putendl_fd("   / /  | | ___| |__   ___| | |", STDIN_FILENO);
	ft_putendl_fd("  / /   | |/ __|  _ \\ / _ \\ | |", STDIN_FILENO);
	ft_putendl_fd(" / /____| |\\__ \\ | | |  __/ | |", STDIN_FILENO);
	ft_putendl_fd("\\_____/\\___/___/_| |_|\\___|_|_|", STDIN_FILENO);
	ft_putendl_fd("\n		~pskytta & zraunio", STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
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

static void	cmd_line_reset(t_shell *shell)
{
	if (shell->quote == EOF)
	{
		ft_memset(shell->cmd_line, '\0', ft_strlen(shell->cmd_line));
		init_row_idx(&shell->window);
	}
	else
	{
		input_row_len(shell, &shell->window);
	}
	shell->cmd_idx = 0;
	shell->end = 0;
	NL;
	cmd_line_prompt(shell->quote);
	init_prompt(shell);
}

/*
** In a loop reads input. Parses. Builds tree. Executes tree.
** TREE will be split into separate trees by SEMICOLON
*/
static void	run_shell(t_shell *shell)
{
	t_ast	**tree;

	ft_memset(&tree, 0, sizeof(t_ast *));
	while (TRUE)
	{
		input_read(shell);
		if (shell->end == 1)
		{
			if (shell->quote == EOF)
			{
				history_runtime(shell);
				tree = ast_constructor(shell, parser(shell));
				(void)tree;
			}
			// else
			// 	cursor_row_idx(&shell->window, shell->window.loc);
			cmd_line_reset(shell);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;

	(void)argc;
	(void)argv;
	ft_memset(&shell, 0, sizeof(shell));
	if (envp)
	{
		print_logo();
		init_shell(&shell, envp);
		ft_print_fd(STDOUT_FILENO, "$> ");
		run_shell(&shell);
	}
	else
	{
		kill_mode("exit", &shell);
	}
	return (EXIT_SUCCESS);
}
