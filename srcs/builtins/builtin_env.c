/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/28 13:35:52 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static bool	env_output(char **env_cpy)
{
	int	i;

	i = 0;
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (env_cpy[i])
		ft_print_fd(STDOUT_FILENO, "%s\n", env_cpy[i++]);
	return (true);
}

static bool	env_flag(char **args)
{
	if (ft_strequ("-i", args[1]))
		return (true);
	return (false);
}

bool	builtin_env(t_shell *shell, t_exec data, char **env_cpy)
{
	int	flg;

	flg = env_flag(data.args);
	if (flg == true)
		return (env_temp_i(shell, data));
	else if (data.args[1] && flg == false)
	{
		ft_perror(ENV_USE);
		return (true);
	}
	else
		return (env_output(env_cpy));
	return (true);
}
