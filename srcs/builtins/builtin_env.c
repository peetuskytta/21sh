/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/23 15:24:06 by pskytta          ###   ########.fr       */
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
	return (false)
}

/* static void	env_temp_addvar(char **args, char **env_cpy)
{

} */

static bool env_temp_empty

static bool	env_temp_empty(t_shell *shell, t_exec *data, char **env_cpy)
{
	int	i;

	if (data.args[2] != NULL)
		return (false);
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

	// replace the data.cmd with the nth data.arg which doesn't have '='
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
	int i;
	int	flg;

	flg = env_flag(data.args);
	if (flg == true)
		return (env_temp_empty(shell, data, env_cpy))
	else if (data.args[1] != NULL && flg == false)
	{
		//env_temp_addvar(data.args, env_cpy);
		//env $VALID_ENV_NAME
		//env temporary env
		//env misformatted_anything
		//env command
		;
	}
	else
		return (env_output(env_cpy));
}
