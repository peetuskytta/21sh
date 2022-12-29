/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:15:27 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/29 10:58:48 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	fetch_envp(t_shell *shell, char **environ, int count)
{
	int			i;

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
	shell->tty = ttyname(STDIN_FILENO);
	if (!shell->tty)
	{
		ft_perror("ttyname() failed to retrieve terminal name.");
		exit(SYSTEM_CALL_FAIL);
	}
}

void	init_shell(t_shell *shell, char **environ)
{
	shell->cmd_line = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	shell->rev_cmd = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	allocation_check((void *)&shell->cmd_line);
	allocation_check((void *)&shell->rev_cmd);
	shell->cmd_idx = 0;
	shell->prmpt_len = 3;
	shell->window.loc = 3;
	shell->quote = EOF;
	init_term();
	init_window(&shell->window);
	fetch_envp(shell, environ, env_variable_counter(environ));
	fetch_ttyname(shell);
	history_fetch(shell);
}
