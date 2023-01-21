/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 10:01:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

static void	env_temp(t_shell *shell, char *args)
{
	
}

void	builtin_env(t_shell *shell, t_exec data)
{
	int i;

	if (shell->flg == 1)
		env_temp(shell, data.args);
	else if (data.args)
	{
		//env $VALID_ENV_NAME
		//env temporary env
		//env misformatted_anything
		//env command
	}
	else
	{
		i = 0;
		while (shell->environ[i])
			ft_print_fd(STDOUT_FILENO, "%s\n", shell->environ[i++]);
	}
}
