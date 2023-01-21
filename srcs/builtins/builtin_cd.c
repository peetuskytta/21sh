/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:03:07 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 15:21:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static bool	path_permission_loop(char **split, const char *path, int i)
{
	struct stat	stats;
	char		temp[8192];

	ft_memset(temp, '\0', 8192);
	while (TRUE)
	{
		if (split[i] == NULL)
			break ;
		if (temp[ft_strlen(temp)] != '/')
			ft_strcat(temp, "/");
		if (ft_strstr(split[i], ".."))
			ft_strcat(temp, split[i]);
		if (lstat(temp, &stats) == 0)
		{
			if (!(stats.st_mode & X_OK))
				return (cd_error_message((char *)path, 4));
		}
		else
			return (cd_error_message((char *)path, 2));
		if (temp[ft_strlen(temp)] != '/')
			ft_strcat(temp, "/");
		i++;
	}
	return (true);
}

static bool	check_access(t_exec *data)
{
	char	**split;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (ft_strchr(data->args[1], '/'))
	{
		split = ft_strsplit(data->args[1] + i, '/');
		ret = path_permission_loop(split, data->args[1], 0);
		ft_arr_free(split);
		if (ret == 3)
			return (3);
	}
	return (true);
}

/*
**	First checks to define the continuation of the cd command. If it ends up
**	in the last line it will check the existence of the Path given.
*/
static bool	initial_checks(t_exec *data)
{
	if (ft_strequ(data->args[1], "-") == 1)
		return (handle_cd_dash(data, 0, 0));
	if (data->args[1] == NULL || ft_strequ(data->args[1], "--") == 1
		|| data->args[1][0] == '\0')
		return (false);
	return (check_access(data));
}

void	builtin_cd(t_shell *shell, t_exec data)
{
	bool	checks;

	fetch_current_working_directory(&data);
	if (data.args[2] == NULL)
	{
		checks = initial_checks(&data);
		if (checks == 1)
			change_to_token(data, data.args[1]);
		if (checks == 0)
			handle_home(data);
		if (checks == 3)
			return ;
	}
	else
		ft_perror(CD_ARG_NO);
}
