/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_slash_access.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:20:49 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 08:57:15 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

bool	exec_slash_access(t_exec *data, char **bin_path)
{
	if (access(data->cmd, F_OK) == -1)
	{
		ft_putstr_fd("shell: ", STDERR_FILENO);
		ft_putstr_fd(data->cmd, STDERR_FILENO);
		ft_perror(NO_FILE_OR_DIR);
		return (false);
	}
	if (access(data->cmd, X_OK) == -1)
	{
		ft_putstr_fd("shell: ", STDERR_FILENO);
		ft_putstr_fd(data->cmd, STDERR_FILENO);
		ft_perror(EXEC_NO_ACCESS);
		return (false);
	}
	else
		*bin_path = ft_strdup(data->cmd);
	return (true);
}
