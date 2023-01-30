/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_temp_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:09:23 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 13:34:28 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static bool	is_command(t_exec *data, int i)
{
	if (ft_strchr(data->args[i], '='))
		return (false);
	return (true);
}

static bool	env_i_no_cmd(t_exec data, int i)
{
	while (data.args[i])
	{
		if (ft_strchr(data.args[i], '='))
			ft_print_fd(STDOUT_FILENO, "%s\n", data.args[i]);
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
		return (env_i_no_cmd(data, 1));
	return (true);
}
