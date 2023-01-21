/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:15:27 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/20 15:55:21 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	fetch_envp(t_shell *shell, char **environ, int count)
{
	int	i;

	i = 0;
	shell->environ = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	allocation_check((void *)&shell->environ);
	while (environ[i] != NULL)
	{
		shell->environ[i] = ft_strdup(environ[i]);
		allocation_check((void *)&shell->environ[i]);
		i++;
	}
	shell->environ[i] = NULL;
}

static void	fetch_ttyname(t_shell *shell)
{
	if (!isatty(1))
		shell->stdout_fd = open(ttyname(ttyslot()), O_RDWR);
	if (shell->stdout_fd == -1)
		ft_perror(STDOUT_FAIL);
	shell->tty = ttyname(STDIN_FILENO);
	if (!shell->tty)
		ft_perror("ttyname() failed to retrieve terminal name.");
}

static void	init_allocations(t_shell *shell)
{
	shell->cmd_line = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	shell->rev_cmd = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	shell->temp = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	shell->input = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	shell->clipbrd = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	shell->q_input = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF * 2 + 1));
	allocation_check((void *)&shell->cmd_line);
	allocation_check((void *)&shell->rev_cmd);
	allocation_check((void *)&shell->temp);
	allocation_check((void *)&shell->input);
	allocation_check((void *)&shell->clipbrd);
	allocation_check((void *)&shell->q_input);
}

void	init_shell(t_shell *shell, char **environ)
{
	init_allocations(shell);
	shell->cmd_idx = 0;
	shell->prmpt_len = 3;
	shell->quote = EOF;
	init_term();
	cursor_find(shell, &shell->window);
	init_window(shell, &shell->window);
	fetch_envp(shell, environ, env_variable_counter(environ));
	fetch_ttyname(shell);
	history_fetch(shell);
}
