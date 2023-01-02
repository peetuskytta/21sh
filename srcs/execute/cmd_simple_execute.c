/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:18:29 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 16:13:48 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	clear_data(t_exec *data)
{
	int	i;

	i = 0;
	while (data->args[i])
	{
		ft_strdel((void *)&data->args[i]);
		i++;
	}
}

void	cmd_simple_execute(t_exec data, char **path, char **env_cpy)
{
	// builtin OR binary (maybe function pointers?)
	// if no binary found set ERRNO and STDERR "no command found"
	clear_data(&data);
	(void)path;
	(void)env_cpy;
}