/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:18:03 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 17:18:03 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

bool	exec_binary_check(char *bin_path, char *cmd)
{
	// if (bin_path == NULL)
	// 	return (false);
	if (access(bin_path, F_OK) == -1)
	{
		ft_putstr_fd("shell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_perror(CMD_NOT_FOUND);
		return (false);
	}
	return (true);
}
