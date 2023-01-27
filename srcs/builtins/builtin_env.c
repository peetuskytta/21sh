/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/27 15:57:37 by pskytta          ###   ########.fr       */
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

static bool is_command(t_exec *data, int i)
{
	if (ft_strchr(data->args[i], '='))
		return (false);
	return (true);
}

static bool	env_i_no_cmd(t_exec data, int i)
{
	//ft_putchar_fd('\n', STDOUT_FILENO);
	while (data.args[i])
	{
		if (ft_strchr(data.args[i], '='))
			ft_print_fd(STDOUT_FILENO, "%s\n", data.args[i]);
		i++;
	}
	return (false);
}

static bool	env_temp_i(t_shell *shell, t_exec data)
{
	t_exec	new;

	if (data.args[2] == NULL)
		return (false);
	ft_memset(&new, 0, sizeof(new));
	if (is_command(&data, 2))
		return (env_cdm(shell, new, data, 2));
	else
		return (env_i_no_cmd(data, 1));
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
