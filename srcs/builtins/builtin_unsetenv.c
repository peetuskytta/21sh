/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:34:37 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/24 14:30:57 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	verify_value(char *name)
{
	if (name == NULL || ft_strlen(name) == 0)
		return (0);
	else if (ft_strchr(name, '='))
		return (-1);
	else
		return (1);
}

static int	unset_errors(char *name, int index)
{
	if (verify_value(name) != 1)
	{
		ft_memdel((void *)&name);
		if (verify_value(name) == -1)
			ft_perror(INVALID_CHAR);
		else
			ft_perror(UNSETENV_USAGE);
		return (-1);
	}
	else if (index == -1)
	{
		ft_memdel((void *)&name);
		return (-1);
	}
	else
		return (1);
}

void	builtin_unsetenv(t_shell *shell, t_exec data)
{
	int	index;

	index = is_strenv(data.args[1], shell->environ);
	if (unset_errors(data.args[1], index) == -1)
		return ;
	ft_arrtrim(shell->environ, index);
}
