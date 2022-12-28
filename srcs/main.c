/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/28 15:28:49 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/* static void	print_zplogo()
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
} */

static void	cmd_line_reset(t_shell *shell)
{
	ft_memset(shell->cmd_line, '\0', ft_strlen(shell->cmd_line));
	shell->cmd_idx = 0;
	shell->end = 0;
	NL;
	cmd_line_prompt(shell->quote);
}

/*
** We have to close the STDIN, STDOUT, and STDERR before re-opening them.
** This way we get the right 0,1,2 as the filedescriptors.
*/
static void	reset_terminal(char *terminal)
{
	close(STDIN_FILENO);
	open(terminal, O_RDWR);
	close(STDOUT_FILENO);
	open(terminal, O_RDWR);
	close(STDERR_FILENO);
	open(terminal, O_RDWR);
}

/*
** In a loop reads input. Parses. Builds tree. Executes tree.
** TREE will be split into separate trees by SEMICOLON
*/
static void	run_shell(t_shell *shell)
{
	t_ast	**tree;

	tree = NULL;
	while (TRUE)
	{
		input_read(shell);
		if (shell->end == 1 && shell->quote == EOF)
		{
			history_runtime(shell);
			tree = ast_constructor(shell, parser(shell));
			(void)tree;
			cmd_line_reset(shell);
			reset_terminal(shell->tty);
		}
		else if (shell->end == 1 && shell->quote != EOF)
		{
			shell->end = 0;
			NL;
			cmd_line_prompt(shell->quote);
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
		init_shell(&shell, envp);
		//print_logo();
		ft_print_fd(STDOUT_FILENO, "$> ");
		// while (TRUE)
		// {
		// 	input_read(&shell);
		// 	if (shell.end == 1 && shell.quote == EOF)
		// 	{
		// 		history_runtime(&shell);
		// 		ft_memset(shell.cmd_line, 0, ft_strlen(shell.cmd_line));
		// 		ft_memset(shell.rev_cmd, 0, ft_strlen(shell.rev_cmd));
		// 		shell.cmd_idx = 0;
		// 		shell.end = 0;
		// 		ft_putendl_fd("", STDOUT_FILENO);
		// 		cmd_line_prompt(shell.quote);
		// 	}
		// }
		run_shell(&shell);
	}
	else
	{
		kill_mode("exit", &shell);
	}
	return (EXIT_SUCCESS);
}
