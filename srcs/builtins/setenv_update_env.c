/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_update_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:31:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 13:16:37 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	setenv_update_env(t_shell *shell, char *name, char *value, int i)
{
	char	*temp;
	char	**arr_temp;

	if (i != -1)
	{
		ft_memset(shell->environ[i], 0, ft_strlen(shell->environ[i]));
		temp = ft_strjoin_free(name, "=", 1);
		allocation_check((void *)&temp);
		ft_memdel((void *)&shell->environ[i]);
		shell->environ[i] = ft_strjoin_free(temp, value, 3);
		allocation_check((void *)&shell->environ[i]);
	}
	else
	{
		i = env_variable_counter(shell->environ) + 1;
		arr_temp = ft_reallocarray(shell->environ, i);
		allocation_check((void *)&arr_temp);
		temp = ft_strjoin(name, "=");
		allocation_check((void *)&temp);
		arr_temp[i - 1] = ft_strjoin(temp, value);
		ft_memdel_range(3, value, temp, name);
		allocation_check((void *)&arr_temp[i - 1]);
		arr_temp[i] = NULL;
		shell->environ = ft_arrdup(arr_temp);
	}
}
