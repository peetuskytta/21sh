/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:17:50 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/28 14:09:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/*
**	copies the environment for the execution. Used to change environment
**	before execution so we don't mess up the parent's environment.
*/
char	**copy_environment(char **environ)
{
	char	**copy;
	int		i;

	i = env_variable_counter(environ);
	copy = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	ft_memset(copy, 0, (i + 2));
	i = 0;
	while (environ[i])
	{
		copy[i] = ft_strdup(environ[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
