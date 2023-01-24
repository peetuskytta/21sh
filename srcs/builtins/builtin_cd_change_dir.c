// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   builtin_cd_change_dir.c                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/22 11:21:02 by pskytta           #+#    #+#             */
// /*   Updated: 2023/01/22 11:38:27 by pskytta          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/shell.h"

// static void	dir_change(const char *dir_path)
// {
// 	if (access(dir_path, F_OK) == 0)
// 	{
// 		if (access(dir_path, X_OK) != 0)
// 			ft_perror(CD_NO_ACCESS);
// 	}
// 	else
// 		ft_perror(NO_FILE_OR_DIR);
// }

// int	builtin_cd_change_dir(t_shell *shell, t_exec *data)
// {
// 	if (builtin_cd_access(data) == CD_NORMAL)
// 		directory_work(shell, data->args[1]);
// }

// void	directory_work(t_shell *shell, const char *dir_path)
// {
// 	char *temp;
// 	int i = 0;

// 	temp = NULL;
// 	if (chdir(dir_path) != 0)
// 	{
// 		dir_change(dir_path);
// 		return ;
// 	}
// 	if (shell->pipe == true) // in pipe we want to change the dir but revert the change back
// 	{
// 		shell->pipe = false;
// 		temp =  ft_strdup(getenv("PWD"));
// 		builtin_cd_change_dir(shell, temp);
// 		ft_memdel((void *)&temp);
// 	}
// 	temp = ft_strdup("OLDPWD");
// 	i = is_strenv(temp, shell->environ);
// 	setenv_update_env(shell, temp, ft_strdup(getenv("OLDPWD")), i);
// 	temp = ft_strdup("PWD");
// 	i = is_strenv(temp, shell->environ);
// 	setenv_update_env(shell, temp, ft_strdup(dir_path), i);
// }
