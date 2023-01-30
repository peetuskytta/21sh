/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/30 10:19:11 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

t_shell	*g_shell;

static void	cmd_line_reset(t_shell *shell, t_win *window)
{
	if (shell->quote == EOF)
		ft_memset(shell->q_input, '\0', sizeof(char) * (MAX_BUFF * 2 + 1));
	if (shell->quote != EOF)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		window->current_row++;
	}
	ft_memset(window->row_idx, '\0', sizeof(char *) * (MAX_BUFF + 1));
	ft_memset(shell->cmd_line, '\0', sizeof(char) * (MAX_BUFF + 1));
	window->row_idx[window->idx] = &shell->cmd_line[0];
	ft_memset(shell->temp, '\0', sizeof(char) * (MAX_BUFF + 1));
	ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	shell->cmd_idx = 0;
	shell->end = 0;
	cmd_line_prompt(shell->quote);
	init_prompt(shell);
	window->loc = shell->prmpt_len;
/* 	ft_print_fd(open("file", O_RDWR | O_APPEND), "window->loc:		%d\n", window->loc);
	ft_print_fd(open("file", O_RDWR | O_APPEND), "shell->quote:		%d\n", shell->quote);
	ft_print_fd(open("file", O_RDWR | O_APPEND), "shell->end:		%d\n", shell->end);
	ft_print_fd(open("file", O_RDWR | O_APPEND), "shell->cmd_idx:	%d\n", shell->cmd_idx);
	ft_print_fd(open("file", O_RDWR | O_APPEND), "shell->cmd_line:	%c\n", shell->cmd_line[0]);
	ft_print_fd(open("file", O_RDWR | O_APPEND), "window->idx:	%d\n", window->idx);
	ft_print_fd(open("file", O_RDWR | O_APPEND), "window->row_idx[window->idx]:	%s\n\n", &shell->window.row_idx[window->idx]); */
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
		signal_listen();
		input_read(shell);
		if (shell->end == 1)
		{
			if (shell->quote == EOF)
			{
				ft_putchar_fd('\n', STDOUT_FILENO);
				history_runtime(shell);
				tree = ast_constructor(shell, parser(shell));
				if (tree)
				{
					exec_tree(tree, shell);
				}
			}
			else
				ft_putchar_fd('\n', STDOUT_FILENO);
			cmd_line_reset(shell, &shell->window);
			cursor_find(shell, &shell->window);
			cursor_load(&shell->window, -1);
			init_in_out_err(shell->tty);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;

	(void)argc;
	(void)argv;
	g_shell = &shell;
	ft_memset(&shell, 0, sizeof(shell));
	if (envp)
	{
		print_logo();
		cmd_line_prompt(EOF);
		init_shell(&shell, envp);
		cursor_load(&shell.window, 0);
		run_shell(&shell);
	}
	else
		kill_mode("exit\n", &shell);
	return (EXIT_SUCCESS);
}
