/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_update_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:31:58 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 16:51:24 by pskytta          ###   ########.fr       */
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
		shell->environ[i] = ft_strjoin_free(temp, value, 3);
	}
	else
	{
		ft_printf("%i\n", i);
		i = shell->env_nbr + 1;
		arr_temp = ft_reallocarray(shell->environ, i);
		arr_temp[--i] = ft_memalloc(ft_strlen(value) + ft_strlen(name) + 1);
		temp = ft_strjoin_free(name, "=", 1);
		arr_temp[i] = ft_strjoin_free(temp, value, 3);
		shell->environ = ft_arrdup(arr_temp);
		shell->env_nbr++;
	}
//	i = 0;
//	while (shell->environ[i])
//		ft_printf("%s\n", shell->environ[i++]);
}
