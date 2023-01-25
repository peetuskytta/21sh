/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:01:14 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 14:58:00 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildin.h"

static int	access_check(char *temp)
{
	if (access(temp, F_OK) == 0)
	{
		if (ft_is_directory(temp) == 0)
		{
			ft_perror(temp);
			return (CD_NO_FILE);
		}
		if (access(temp, X_OK) == -1)
		{
			ft_perror(temp);
			return (CD_PERM);
		}
		return (1);
	}
	return (-1);
}

static int	path_permission_loop(char **split, char *cwd, int i)
{
	char		temp[MAX_BUFF];
	int			ret;

	ft_memset(temp, '\0', MAX_BUFF);
	ft_strcat(temp, cwd);
	while (split[i])
	{
		if (split[i] == NULL)
			break ;
		if (temp[ft_strlen(temp)] != '/')
			ft_strcat(temp, "/");
		ft_strcat(temp, split[i]);
		ft_putendl(temp);
		ret = access_check(temp);
		if (ret != 1)
			return (ret);
		else
			return (CD_NO_FILE);
		if (temp[ft_strlen(temp)] != '/')
			ft_strcat(temp, "/");
		i++;
	}
	return (CD_NORMAL);
}

int	builtin_cd_access(t_exec *data, int ret)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	if (ft_strchr(data->args[1], '/'))
	{
		split = ft_strsplit(data->args[1], '/');
		ret = path_permission_loop(split, getenv("PWD"), 0);
		ft_arr_free((void *)&split);
		if (ret == CD_PERM || ret == CD_NO_FILE)
		{
			if (ret == CD_PERM)
				ft_perror(CD_NO_ACCESS);
			else
				ft_perror(NO_FILE_OR_DIR);
			ret = CD_ERR;
		}
	}
	return (ret);
}
