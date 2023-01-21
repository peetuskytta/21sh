/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/21 16:10:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	cmd_line_reset(t_shell *shell, t_win *window)
{
	if (shell->quote == EOF)
		ft_memset(shell->q_input, '\0', sizeof(char) * (MAX_BUFF * 2 + 1));
	if (shell->quote != EOF)
		window->current_row++;
	window->idx = 0;
	ft_memset(window->row_idx, '\0', sizeof(char *) * (MAX_BUFF));
	ft_memset(shell->cmd_line, '\0', sizeof(char) * (MAX_BUFF + 1));
	window->row_idx[window->idx] = &shell->cmd_line[0];
	ft_memset(shell->temp, '\0', sizeof(char) * (MAX_BUFF + 1));
	ft_memset(shell->input, '\0', sizeof(char) * (MAX_BUFF + 1));
	shell->cmd_idx = 0;
	shell->end = 0;
	ft_putstr_fd("\n", STDOUT_FILENO);
	cmd_line_prompt(shell->quote);
	init_prompt(shell);
	window->loc = shell->prmpt_len;
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
				if (tree)
					exec_tree(tree, shell);
			}
			cmd_line_reset(shell, &shell->window);
			cursor_find(shell, &shell->window);
			cursor_load(&shell->window, -1);
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
		cmd_line_prompt(EOF);
		run_shell(&shell);
	}
	else
		kill_mode("exit\n", &shell);
	return (EXIT_SUCCESS);
}
