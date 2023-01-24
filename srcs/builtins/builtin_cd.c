/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:03:07 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/24 14:11:51 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	builtin_cd(t_shell *shell, t_exec data)
{
	int	checks;

	if (data.args[2] == NULL)
	{
		checks = builtin_cd_access(&data);
		if (checks == CD_NORMAL)
			checks = builtin_cd_change_dir(shell, &data);
		else if (checks == CD_HOME)
			builtin_cd_home(shell, is_strenv("HOME", shell->environ));
		else if (checks == CD_PREVIOUS)
		{
				ft_perror("cd to OLDPWD\n");//change to previous dir from the OLDPWD
		}
		if (checks == CD_ERR)
			return ;
	}
	else
		ft_perror(CD_ARG_NO);
}
