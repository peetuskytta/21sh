/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_find_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:06:28 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 11:06:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	*ft_memdel_return(void **delete)
{
	ft_memdel((void *)&delete);
	return (NULL);
}

static char	*exec_binary_path(char **path, char *cmd)
{
	struct stat		buf;
	char			*temp;
	char			**cpy;

	cpy = path;
	temp = NULL;
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
	if (ft_is_directory(temp))
		return (ft_memdel_return((void *)&temp));
	return (temp);
}

char	*exec_find_binary(char **path, char *cmd)
{
	if (cmd == NULL || path == NULL)
		return (NULL);
	if (ft_is_directory(cmd))
	{
		ft_print_fd(STDERR_FILENO, "21sh: %s: Is a directory", cmd);
		return (NULL);
	}
	if (cmd[0] == '\0')
		return (NULL);
	return (exec_binary_path(path, cmd));
}
