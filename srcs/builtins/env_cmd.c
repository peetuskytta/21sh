/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:17:03 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/29 17:30:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	execute_env(t_shell *shell, t_exec new, char **env_cpy)
{
	char	*bin_path;

	(void)shell;
	bin_path = NULL;
	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), new.cmd);
	if (redirection_loop(&new) && exec_binary_check(&bin_path, new))
		execve(bin_path, new.args, env_cpy);
	ft_strdel((void *)&bin_path);
}

static void	cmd_change_value(t_shell *sh, t_exec n, t_exec d, char **env)
{
	int	i;

	i = 0;
	(void)d;
	n.cmd = ft_strdup(n.args[0]);
	execute_env(sh, n, env);
	ft_arr_free((void *)&env);
	i = 0;
	while (n.args[i])
		ft_strdel(&n.args[i++]);
	ft_strdel(&n.cmd);
}

bool	env_cdm(t_shell *shell, t_exec new, t_exec data, int i)
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
		i++;
	}
	cmd_change_value(shell, new, data, env_cpy);
	return (false);
}
