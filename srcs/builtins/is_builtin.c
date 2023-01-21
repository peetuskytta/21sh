/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:27:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 13:30:01 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

bool	is_builtin(char *cmd)
{
	if (ft_strequ("echo", cmd) || ft_strequ("setenv", cmd)
		|| ft_strequ("unsetenv", cmd) || ft_strequ("env", cmd)
		|| ft_strequ("cd", cmd))
		return (true);
	else
		return (false);
}
