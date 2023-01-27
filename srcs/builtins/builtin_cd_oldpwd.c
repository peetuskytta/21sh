/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_oldpwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:37:21 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/27 10:27:21 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	cd_oldpwd_value(t_shell *shell, t_exec *data, int idx)
{
	//ft_memdel((void *)&data->args[1]);
	data->args[1] = ft_strdup(shell->environ[idx] + 7);
	allocation_check((void *)&data->args[1]);
}

void	builtin_cd_oldpwd(t_shell *shell, t_exec *data, int idx)
{
	if (idx == -1)
	{
		ft_perror(CD_NO_OLDPWD);
		return ;
	}
	else
	{
		cd_oldpwd_value(shell, data, idx);
		builtin_cd_change_dir(shell, data);
		ft_putendl_fd(data->args[1], STDOUT_FILENO);
		//ft_memdel((void *)&data->args[1]);
	}
}