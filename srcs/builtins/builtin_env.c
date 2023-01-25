/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 18:25:54 by pskytta          ###   ########.fr       */
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

void	swap_char_ptr(char **first, char **second) //maybe a function to add to libft
{
	char	*temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

static bool is_command(t_exec *data, int i)
{
	while (data->args[i])
	{
		if (!ft_strchr(data->args[i], '='))
			return (true);
		i++;
	}
	if (i >= MAX_REDIR / 2)
	{
		ft_perror("shell: too many variables\n");
		return (false);
	}
	return (false);
}

/* static void	env_temp_addvar(char **args, char **env_cpy)
{

}*/

static void	execute_env(t_shell *shell, t_exec new, char **env_cpy)
{
	char	*bin_path;

	bin_path = NULL;
	if (is_builtin(new.cmd))
	{
		builtin_execute(shell, new, env_cpy);
	}
	else
	{
		bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), new.cmd);
		if (redirection_loop(&new) && exec_binary_check(bin_path, new))
			exec_cmd(new, bin_path, env_cpy);
		ft_strdel((void *)&bin_path);
	}
}

static bool	env_cdm(t_shell *shell, t_exec new, t_exec data, int i)
{
	int		idx;
	int		env_idx;
	char	**env_cpy;

	env_idx = 0;
	idx = 0;
	env_cpy = (char **)ft_memalloc(sizeof(char *) * (MAX_REDIR - 1));
	while (data.args[i])
	{
		if (!ft_strchr(data.args[i], '='))
		{
			new.args[idx] = ft_strdup(data.args[i]);
			idx++;
		}
		if (ft_strchr(data.args[i], '='))
		{
			env_cpy[env_idx] = ft_strdup(data.args[i]);
			env_idx++;
		}
		ft_strdel(&data.args[i]);
		i++;
	}
/* 	i = 0;
	NL;
	while (new.args[i])
		ft_putendl(new.args[i++]);
 	i = 0;
	NL;
	while (env_cpy[i])
		ft_putendl(env_cpy[i++]); */
	new.cmd = ft_strdup(new.args[0]);
	execute_env(shell, new, env_cpy);
	ft_arr_free((void *)&env_cpy);
	i = 0;
	ft_strdel(&data.args[1]);
	while (new.args[i])
		ft_strdel(&new.args[i++]);
	ft_strdel(&new.cmd);
	return (true);
}

static bool	env_i_no_cmd(t_exec data, int i)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (data.args[i])
	{
		if (ft_strchr(data.args[i], '='))
			ft_print_fd(STDOUT_FILENO, "%s\n", data.args[i]);
		ft_strdel(&data.args[i]);
		i++;
	}
	return (true);
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
	{
		return (env_i_no_cmd(data, 1));
	}
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

	ft_putnbr_endl(data.fds.fd_out);
	flg = env_flag(data.args);
	(void)shell;
	if (flg == true)
		return (env_temp_i(shell, data));
	if (data.args[1] != NULL && flg == false)
	{
		//env_temp_addvar(data.args, env_cpy);
		//env $VALID_ENV_NAME
		//env temporary env
		//env misformatted_anything
		//env command
		return (true);
	}
	else
	{
		DB;
		return (env_output(env_cpy));
	}
	return (true);
}
