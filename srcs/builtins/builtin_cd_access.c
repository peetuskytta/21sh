/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:01:14 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/24 14:02:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildin.h"

static int	path_permission_loop(char **split, int i)
{
	char		temp[MAX_BUFF];

	ft_memset(temp, '\0', MAX_BUFF);
	while (true)
	{
		if (split[i] == NULL)
			break ;
		if (temp[ft_strlen(temp)] != '/')
			ft_strcat(temp, "/");
		ft_strcat(temp, split[i]);
		NL;
		ft_putendl(temp);
		if (access(temp, F_OK) == 0)
		{
			if (ft_is_directory(temp) == 0)
				return (CD_NO_FILE);
			if (access(temp, X_OK) == -1)
				return (CD_PERM);
		}
		else
			return (CD_NO_FILE);
		i++;
	}
	return (CD_NORMAL);
}

static int	check_access(t_exec *data)
{
	char	**split;
	int		ret;
	int		i;

	i = 0;
	ret = CD_NORMAL;
	if (ft_strchr(data->args[1], '/'))
	{
		split = ft_strsplit(data->args[1] + i, '/');
		ret = path_permission_loop(split, 0);
		ft_arr_free((void *)&split);
		if (ret > 6)
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

/*
**	First checks to define the continuation of the cd command. If it ends up
**	in the last line it will check the existence of the Path given.
*/
int	builtin_cd_access(t_exec *data)
{
	if (ft_strequ(data->args[1], "-") == 1)
		return (CD_PREVIOUS);
	if (data->args[1] == NULL || ft_strequ(data->args[1], "--") == 1
		|| data->args[1][0] == '\0')
		return (CD_HOME);
	return (check_access(data));
}
