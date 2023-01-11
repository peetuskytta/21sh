/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/11 16:54:34 by pskytta          ###   ########.fr       */
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
		ft_memset(shell->cmd_line, '\0', sizeof(char) * (MAX_BUFF + 1));
		ft_memset(shell->temp, '\0', sizeof(char) * (MAX_BUFF + 1));
		init_row_idx(&shell->window);
	}
	else
		input_row_len(shell, &shell->window);
	shell->cmd_idx = 0;
	shell->end = 0;
	//NL;
	cmd_line_prompt(shell->quote);
	init_prompt(shell);
	shell->window.loc = shell->prmpt_len;
}

/*
** We have to close the STDIN, STDOUT, and STDERR before re-opening them.
** This way we get the right 0,1,2 as the filedescriptors.
*/
/* static void	reset_terminal(char *terminal)
{
	close(STDIN_FILENO);
	open(terminal, O_RDWR);
	close(STDOUT_FILENO);
	open(terminal, O_RDWR);
	close(STDERR_FILENO);
	open(terminal, O_RDWR);
} */

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
				if (tree)
					exec_tree(tree, shell);
			}
			cursor_find(shell, &shell->window);
			cmd_line_reset(shell);
			cursor_load(shell, shell->window.loc, shell->window.current_row);
		//	reset_terminal(shell->tty);
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
