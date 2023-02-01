/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 13:59:16 by zraunio          ###   ########.fr       */
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
	init_prompt(shell);
	if (shell->flg == 1)
		cmd_line_prompt(shell->quote);
	window->loc = shell->prmpt_len;
	shell->flg = 1;
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
					exec_tree(tree, shell);
			}
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
		init_shell(&shell, envp);
		cmd_line_prompt(EOF);
		cursor_load(&shell.window, 0);
		run_shell(&shell);
	}
	else
		kill_mode("exit\n", &shell);
	return (EXIT_SUCCESS);
}
