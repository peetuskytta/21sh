/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:27:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 14:37:08 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

bool	is_builtin(char *cmd)
{
	if (ft_strequ("echo", cmd) || ft_strequ("setenv", cmd)
		|| ft_strequ("unsetenv", cmd) || ft_strequ("env", cmd)
		|| ft_strequ("cd", cmd) || ft_strequ("exit", cmd))
		return (true);
	else
		return (false);
}
