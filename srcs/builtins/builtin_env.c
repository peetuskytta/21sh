/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/24 14:36:01 by zraunio          ###   ########.fr       */
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
	return (false);
}

void	swap_char_ptr(char **first, char **second) //maybe a function to add to libft
{
	char	*temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

// static bool is_command(t_exec *data, int count, int i)
// {
// 	while (data->args[i])
// 	{
// 		if (!ft_strchr(data->args[i], '='))
// 		{
// 			if (ft_strequ("env", data->args[0]))
// 				swap_char_ptr(&data->args[0], &data->args[i]);
// 		}
// 		i++;
// 	}
// 	if (i > count + 10)
// 	{
// 		ft_perror("shell: too many variables\n");
// 		return (false);
// 	}
// 	return (true);
// }

/* static void	env_temp_addvar(char **args, char **env_cpy)
{

}


static void	env_args_renew(t_exec *data, char **old_env, int i)
{
	int		count;

	count = 0;
	while (old_env[count])
		ft_memdel((void *)&old_env[count++]);
	count = 0;
	while (data->args[i] != NULL)
	{
		if (ft_strchr(data->args[i], '='))
		{
			old_env[count] = ft_strdup(data->args[i]);
			count++;
		}
		i++;
	}
}

static bool	env_temp_empty(t_shell *shell, t_exec *data, char **env_cpy)
{
	(void)shell;
	if (data->args[2] == NULL)
		return (false);
	if (is_command(data, env_variable_counter(env_cpy), 2))
	{
		env_args_renew(data, env_cpy, 2);
		ft_strclr(data->cmd);
		data->cmd = ft_memcpy((void *)data->cmd, (void *)data->args[0], sizeof(char *));
		ft_putendl(data->cmd);
		DB;
		int i = 0;
		while (data->args[i])
			ft_putendl(data->args[i++]);
		DB;
		i = 0;
		while (env_cpy[i])
			ft_putendl(env_cpy[i++]); */
/* 		i = env_variable_counter(env_cpy);
		i = is_strenv("PWD", shell->environ);
		if (i != -1)
			env_cpy[0] = ft_strdup(shell->environ[i]);
		i = is_strenv("SHLVL", shell->environ);
		if (i != -1)
			env_cpy[1] = ft_strdup(shell->environ[i]);
		i = is_strenv("_", shell->environ);
		if (i != -1)
			env_cpy[2] = ft_strdup(shell->environ[i]); */
		//return (false);
// 		return (true);
// 	}
// 	else
// 		return (false);
// 	return (true);
// }

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
	(void)shell;
	// if (flg == true)
	// 	return (env_temp_empty(shell, &data, env_cpy));
	if (data.args[1] != NULL && flg == false)
	{
		//env_temp_addvar(data.args, env_cpy);
		//env $VALID_ENV_NAME
		//env temporary env
		//env misformatted_anything
		//env command
		return (false);
	}
	else
		return (env_output(env_cpy));
	return (false);
}
