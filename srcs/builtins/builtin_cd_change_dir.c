/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_change_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:39:37 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 14:34:49 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static void	directory_change(const char *dir_path)
{
	if (access(dir_path, F_OK) == 0)
	{
		if (access(dir_path, X_OK) != 0)
		{
			ft_perror(CD_SH);
			ft_perror(dir_path);
			ft_perror(CD_NO_ACCESS);
		}
	}
	else
	{
		ft_perror(CD_SH);
		ft_perror(dir_path);
		ft_perror(NO_FILE_OR_DIR);
	}
}

static char	*join_n_and_v(char *name, char *value)
{
	char	temp[8192];

	ft_memset(temp, '\0', 8192);
	ft_strcat(temp, name);
	ft_strcat(temp, "=");
	name = temp;
	return (ft_strjoin(name, value));
}

static void	modify_env(t_shell *shell, char *name, char *value, int i)
{
	i = is_strenv(name, shell->environ);
	ft_memdel((void *)&shell->environ[i]);
	shell->environ[i] = join_n_and_v(name, value);
}

static void	directory_work(t_shell *shell, t_exec *data)
{
	char	*temp;

	temp = NULL;
	if (is_strenv("OLDPWD", shell->environ) < 0)
		setenv_update_env(shell, ft_strdup("OLDPWD"), shell->cwd, -1);
	else
		modify_env(shell, "OLDPWD", shell->cwd, 0);
	if (chdir(data->args[1]) != 0)
	{
		directory_change(data->args[1]);
		return ;
	}
	if (shell->pipe == true)
	{
		shell->pipe = false;
		temp = ft_strdup(shell->environ[is_strenv("PWD", shell->environ)]);
		directory_work(shell, data);
		ft_memdel((void *)&temp);
	}
	builtin_cd_fetch_cwd(shell);
	if (is_strenv("PWD", shell->environ) < 0)
		setenv_update_env(shell, ft_strdup("PWD"), shell->cwd, -1);
	else
		modify_env(shell, "PWD", shell->cwd, 0);
}

int	builtin_cd_change_dir(t_shell *shell, t_exec *data)
{
	builtin_cd_fetch_cwd(shell);
	if (builtin_cd_access(data->args[1], CD_NORMAL) == CD_NORMAL)
		directory_work(shell, data);
	return (CD_ERR);
}
