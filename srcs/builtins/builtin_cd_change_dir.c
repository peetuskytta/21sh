/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_change_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:39:37 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/24 16:30:23 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	directory_change(const char *dir_path)
{
	if (access(dir_path, F_OK) == 0)
	{
		if (access(dir_path, X_OK) != 0)
			ft_perror(CD_NO_ACCESS);
	}
	else
		ft_perror(NO_FILE_OR_DIR);
}

static void	directory_work(t_shell *shell, t_exec *data)
{
	char *temp;
	int i = 0;

	temp = NULL;
	if (chdir(data->args[1]) != 0)
	{
		directory_change(data->args[1]);
		return ;
	}
	if (shell->pipe == true) // in pipe we want to change the dir but revert the change back
	{
		shell->pipe = false;
		temp = ft_strdup(shell->environ[is_strenv("PWD", shell->environ)]);
		directory_work(shell, data);
		ft_memdel((void *)&temp);
	}
	temp = ft_strdup("OLDPWD");
	i = is_strenv(temp, shell->environ);
	setenv_update_env(shell, temp, ft_strdup(getenv("OLDPWD")), i);
	temp = ft_strdup("PWD");
	i = is_strenv(temp, shell->environ);
	setenv_update_env(shell, temp, ft_strdup(data->args[1]), i);
}

int	builtin_cd_change_dir(t_shell *shell, t_exec *data)
{
	if (builtin_cd_access(data, CD_NORMAL) == CD_NORMAL)
		directory_work(shell, data);
	return (CD_ERR);
}
