/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_change_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:21:02 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/22 11:38:27 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	builtin_cd_change_dir(t_shell *shell, const char *dir_path)
{
	(void)shell;
	// try to change and then act if errors
/* 	if (shell->pipe == true)
	{
		//change_in_pipe(dir_path);
		shell->pipe = false;
		return ;
	} */
/* 	else
	{ */
		if (chdir(dir_path) != 0)
		{
			if (access(dir_path, F_OK) == 0)
			{
				if (access(dir_path, X_OK) != 0)
					ft_perror(CD_NO_ACCESS);
			}
			else
				ft_perror(NO_FILE_OR_DIR);
			return ;
		}
	//}
	// change the OLDPWD to be the current PWD
	// change the PWD to match the dir_path
}