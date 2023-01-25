/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 09:48:08 by pskytta          ###   ########.fr       */
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

static bool is_command(t_exec *new, int i)
{
	while (new->args[i])
	{
		if (!ft_strchr(new->args[i], '='))
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

void	execute_env(t_exec new, char **env_cpy)
{
	char	*bin_path;

	bin_path = NULL;
	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), new.cmd);
	if (redirection_loop(&new) && exec_binary_check(bin_path, new))
		exec_cmd(new, bin_path, env_cpy);
	ft_strdel((void *)&bin_path);
}

void	env_args_renew(t_exec new, int i)
{
	(void)new;
	(void)i;
}

static bool	empty_env_i_flag(t_exec new)
{
	int		i;

	i = 1;
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (new.args[i])
	{
		if (ft_strchr(new.args[i], '='))
			ft_print_fd(STDOUT_FILENO, "%s\n", new.args[i]);
		ft_strdel(&new.args[i]);
		i++;
	}
	return (false);
}

static bool	env_temp_empty(t_exec data)
{
	t_exec	new;

	if (data.args[2] == NULL)
		return (false);
	ft_memset(&new, 0, sizeof(new));
	ft_memcpy(&new, &data, sizeof(t_exec));
	if (is_command(&new, 2))
	{
		return (0);
	}
	else
		return (empty_env_i_flag(new));
	/* {
		env_args_renew(data, 2);

		ft_putendl(data.cmd);
		DB;
		int i = 0;
		while (data.args[i])
			ft_putendl(data.args[i++]);
		DB;
		i = 0;
		while (env_cpy[i])
			ft_putendl(env_cpy[i++]);

		real_exec(new);
		return (true);
	} */
	return (false);
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
	(void)shell;
	if (flg == true)
		return (env_temp_empty(data));
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
