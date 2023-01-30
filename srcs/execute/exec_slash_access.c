/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_slash_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:20:49 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/30 16:23:11 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	exec_slash_access(t_exec *data, char **bin_path)
{
	if (access(data->cmd, F_OK) == -1)
	{
		ft_perror(NO_FILE_OR_DIR);
		return ;
	}
	else if (access(data->cmd, X_OK) == -1)
	{
		ft_perror(EXEC_NO_ACCESS);
		return ;
	}
	else
		*bin_path = ft_strdup(data->cmd);
}