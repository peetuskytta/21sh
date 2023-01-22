/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:25:24 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 10:59:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDIN_H
# define BUILDIN_H
# include "shell.h"
# include "structs.h"

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
void	builtin_env(t_shell *shell, t_exec data);
void	builtin_unsetenv(t_shell *shell, t_exec data);
void	builtin_echo(t_shell *shell, t_exec data);
void	builtin_execute(t_shell *shell, t_exec data);

#endif
