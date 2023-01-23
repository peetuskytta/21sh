/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:25:24 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/23 14:09:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDIN_H
# define BUILDIN_H
# include "shell.h"
# include "structs.h"

typedef enum e_cd
{
	CD_DIR = 3,
	CD_HOME = 4,
	CD_NORMAL = 5,
	CD_PREVIOUS = 6,
	CD_NO_FILE = 7,
	CD_PERM = 8,
	CD_ERR = -1,
}	t_cd;

/*
** HELPERS
*/
int		is_strenv(char *name, char **environ);
bool	is_builtin(char *cmd);
void	setenv_update_env(t_shell *shell, char *name, char *value, int i);
/*
** BUILDINS
*/
void	builtin_setenv(t_shell *shell, t_exec data);
void	builtin_env(t_shell *shell, t_exec data, char **env_cpy);
void	builtin_unsetenv(t_shell *shell, t_exec data);
void	builtin_echo(t_shell *shell, t_exec data);
void	builtin_execute(t_shell *shell, t_exec data, char **env_cpy);
void	builtin_cd(t_shell *shell, t_exec data);
void	builtin_cd_change_dir(t_shell *shell, const char *dir_path);

#endif
