/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:15:27 by pskytta           #+#    #+#             */
/*   Updated: 2022/10/31 15:48:38 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/shell.h"

static void	fetch_envp(t_shell *shell, char **environ, int count)
{
	int			i;

	i = 0;
	shell->env = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	allocation_check((void *)&shell->env);
	while (environ[i] != NULL)
	{
		shell->env[i] = ft_strdup(environ[i]);
		allocation_check((void *)&shell->env[i]);
		i++;
	}
	shell->env[i] = NULL;
}

void	init_shell(t_shell *shell, char **environ)
{
	fetch_envp(shell, environ, env_variable_counter(environ));
	// future history fetched from a file or initialized by other means
	// if no history file exists.
}
