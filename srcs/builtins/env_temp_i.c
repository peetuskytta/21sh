/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_temp_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:09:23 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/26 19:10:57 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static bool	is_command(t_exec *data, int i)
{
	while (data->args[i])
	{
		if (!ft_strchr(data->args[i], '='))
			return (true);
		i++;
	}
	if (i >= MAX_REDIR / 2)
	{
		ft_perror(SET_TOO_MANY_ARG);
		return (false);
	}
	return (false);
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
	return (false);
}

bool	env_temp_i(t_shell *shell, t_exec data)
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
