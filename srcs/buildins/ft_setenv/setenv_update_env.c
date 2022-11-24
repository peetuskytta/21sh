/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_update_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:31:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/17 15:50:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

void	setenv_update_env(t_shell *shell, char *name, char *value, int i)
{
	char	*temp;
	char	**arr_temp;

	if (i != -1)
		ft_memset(shell->environ[i], 0, ft_strlen(shell->environ[i]));
	else
	{
		ft_printf("%i\n", i);
		i = shell->env_nbr + 1;
		arr_temp = ft_reallocarray(shell->environ, i);
		shell->environ = ft_arrdup(arr_temp);
		shell->env_nbr++;
	}
	temp = ft_strjoin_free(name, "=", 1);
	shell->environ[i--] = ft_strjoin_free(temp, value, 3);
	i = 0;
	while (shell->environ[i] != NULL)
		ft_printf("%s\n", shell->environ[i++]);
}
