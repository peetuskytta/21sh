/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:06:28 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 11:06:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

char	*exec_binary_path(char **path, char *cmd)
{
	struct	stat	buf;
	char			*temp;
	char			**cpy;

	cpy = path;
	while (*cpy)
	{
		temp = ft_strjoin(*cpy, "/");
		temp = ft_strjoin_free(temp, cmd, 1);
		if (lstat(temp, &buf) == 0)
			break ;
		else
			ft_strdel((void *)&temp);
		cpy++;
	}
	ft_arr_free((void *)&path);
	return (temp);
}