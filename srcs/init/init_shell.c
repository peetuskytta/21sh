/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:15:27 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/12 13:27:36 by zraunio          ###   ########.fr       */
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
	shell->tty = ttyname(STDIN_FILENO);
	if (!shell->tty)
	{
		ft_perror("ttyname() failed to retrieve terminal name.");
		exit(SYSTEM_CALL_FAIL);
	}
	//ft_putendl(shell->tty);
}

void	init_shell(t_shell *shell, char **environ)
{
	shell->cmd_line = (char *)ft_memalloc(sizeof(char) * (MAX_BUFF + 1));
	allocation_check((void *)&shell->cmd_line);
	shell->cmd_idx = 0;
	shell->quote = EOF;
	fetch_envp(shell, environ, env_variable_counter(environ));
	fetch_ttyname(shell);
	// future history fetched from a file or initialized by other means
	// if no history file exists.
}
