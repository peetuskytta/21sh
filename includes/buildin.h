/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:25:24 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/02 16:14:59 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILDIN_H
# define BUILDIN_H
# include "shell.h"
# include "structs.h"

/*
** HELPERS
*/
int		ft_is_strenv(char *name, char **environ);
void	setenv_update_env(t_shell *shell, char *name, char *value, int i);
/*
** BUILDINS
*/
void	ft_setenv(t_shell *shell, char *args);
void	ft_env(t_shell *shell, char **args);
void	ft_unsetenv(t_shell *shell, char *args);
int		ft_echo(char **args, bool n_fl);

# endif
