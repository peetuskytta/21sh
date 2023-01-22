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
	if (chdir(dir_path) != 0)
	{
		if (access(dir_path, F_OK) == 0)
		{
			if (access(dir_path, X_OK) != 0)
				ft_perror(CD_NO_ACCESS);
		}
		else
			ft_perror(NO_FILE_OR_DIR);
	}
	if (shell->pipe == true)
	{
		shell->pipe = false;
		builtin_cd_change_dir(shell, getenv("PWD"));
	}
	char *temp = ft_strdup("OLDPWD");
	int i = ft_is_strenv(temp, shell->environ);
	setenv_update_env(shell, temp, getenv("PWD"), i);
	temp = ft_strdup("PWD");
	i = ft_is_strenv(temp, shell->environ);
	setenv_update_env(shell, temp, (char *)dir_path, i);
	// change the OLDPWD to be the current PWD
	// change the PWD to match the dir_path
}
