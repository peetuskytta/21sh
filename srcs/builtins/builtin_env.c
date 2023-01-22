/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 11:50:04 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

// static void	env_temp(t_shell *shell)
// {
	
// }

static int	env_flag(char **args)
{
	if (ft_strequ("-i", args[1]))
		return (1);
	return (0);
}

void	builtin_env(t_shell *shell, t_exec data)
{
	int i;
	int	flg;

	flg = env_flag(data.args);
	// if (flg == 1)
	// {
	// 	env_temp(shell);
	// 	//run command with execute 
	// }
	// else if (data.args[1] != NULL && flg == 0)
	// {
	// 	env_temp(shell);
	// 	//env $VALID_ENV_NAME
	// 	//env temporary env
	// 	//env misformatted_anything
	// 	//env command
	// }
	// else
	// {
		i = 0;
		ft_putchar_fd('\n', STDOUT_FILENO);
		while (shell->environ[i])
			ft_print_fd(STDOUT_FILENO, "%s\n", shell->environ[i++]);
	// }
}
