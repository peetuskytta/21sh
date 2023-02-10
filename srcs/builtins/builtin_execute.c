/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:30:59 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/10 09:40:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

void	builtin_execute(t_shell *shell, t_exec data, char **env_cpy)
{
	change_in_and_out(&data);
	if (ft_strequ("echo", data.cmd))
		return (builtin_echo(shell, data));
	else if (ft_strequ("setenv", data.cmd))
		return (builtin_setenv(shell, data));
	else if (ft_strequ("unsetenv", data.cmd))
		return (builtin_unsetenv(shell, data));
	else if (ft_strequ("env", data.cmd))
		return ((void)builtin_env(shell, data, env_cpy));
	else if (ft_strequ("exit", data.cmd))
		exit(EXIT_FAILURE);
	else if (ft_strequ("cd", data.cmd))
		return (builtin_cd(shell, data));
	else
		return ((void) -1);
}
