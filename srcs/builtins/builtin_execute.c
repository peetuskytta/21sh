/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:30:59 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 11:04:25 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	builtin_execute(t_shell *shell, t_exec data)
{
	if (ft_strequ("echo", data.cmd))
		return (builtin_echo(shell, data));
	else if (ft_strequ("setenv", data.cmd))
		return (builtin_setenv(shell, data));
	else if (ft_strequ("unsetenv", data.cmd))
		return (builtin_unsetenv(shell, data));
	else if (ft_strequ("env", data.cmd))
		return (builtin_env(shell, data));
	// else if (ft_strequ("cd", data.cmd))
	// 	return (builtin_cd(shell, data));
	else if (ft_strequ("exit", data.cmd))
	{
		//free tree
		kill_mode("exit", shell);
	}
	else
		return ((void) -1);
}
