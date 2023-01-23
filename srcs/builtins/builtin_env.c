/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/23 14:27:46 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	env_temp_addvar(char **args, char **env_cpy)
{
	
}

static void	env_temp(t_shell *shell, char **env_cpy)
{
	int	i;

	i = env_variable_counter(env_cpy);
	ft_memset(env_cpy, '\0', sizeof(char *) * (i + 1));
	i = is_strenv("PWD", shell->environ);
	if (i != -1)
		env_cpy[0] = ft_strdup(shell->environ[i]);
	i = is_strenv("SHLVL", shell->environ);
	if (i != -1)
		env_cpy[1] = ft_strdup(shell->environ[i]);
	i = is_strenv("_", shell->environ);
	if (i != -1)
		env_cpy[2] = ft_strdup(shell->environ[i]);
}

static int	env_flag(char **args)
{
	if (ft_strequ("-i", args[1]))
		return (1);
	return (0);
}

void	builtin_env(t_shell *shell, t_exec data, char **env_cpy)
{
	int i;
	int	flg;

	flg = env_flag(data.args);
	if (flg == 1)
	{
		env_temp(shell, env_cpy);
		// exec_cmd(data, )
	}
	else if (data.args[1] != NULL && flg == 0)
	{
		env_temp_addvar(data.args, env_cpy);
		//env $VALID_ENV_NAME
		//env temporary env
		//env misformatted_anything
		//env command
	}
	else
	{
		i = 0;
		ft_putchar_fd('\n', STDOUT_FILENO);
		while (shell->environ[i])
			ft_print_fd(STDOUT_FILENO, "%s\n", shell->environ[i++]);
	}
}
