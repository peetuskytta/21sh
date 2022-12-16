/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:25:24 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 12:55:46 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILDIN_H
# define BUILDIN_H
# include "shell.h"
# include "structs.h"

/*
** BUILDINS
*/
void	ft_setenv(t_shell *shell, char *args);
int		ft_is_strenv(char *name, char **environ);
void	setenv_update_env(t_shell *shell, char *name, char *value, int i);
void	ft_env(t_shell *shell, char **args);
void	ft_unsetenv(t_shell *shell, char *args);

# endif
