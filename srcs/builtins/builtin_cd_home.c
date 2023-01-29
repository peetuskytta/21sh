/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:29 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/29 18:25:53 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildin.h"

static void	cd_home_value(t_shell *shell, t_exec *data, int idx)
{
	data->args[1] = ft_strdup(shell->environ[idx] + 5);
	allocation_check((void *)&data->args[1]);
}

void	builtin_cd_home(t_shell *shell, t_exec *data, int idx)
{
	if (idx == -1)
	{
		ft_perror(CD_NO_HOME);
		return ;
	}
	else
	{
		cd_home_value(shell, data, idx);
		builtin_cd_change_dir(shell, data);
		ft_memdel((void *)&data->args[1]);
	}
}
