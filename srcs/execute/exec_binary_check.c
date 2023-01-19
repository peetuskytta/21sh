/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:46:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/12 12:46:07 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

bool	exec_binary_check(char *bin_path, t_exec data)
{
	if (!data.cmd && data.redir->file != NULL)
		return (false);
	if (access(bin_path, F_OK) == -1)
	{
		ft_putstr_fd("shell: ", STDERR_FILENO);
		ft_putstr_fd(data.cmd, STDERR_FILENO);
		ft_perror(CMD_NOT_FOUND);
		ft_putchar(CHAR_NEWLINE);
		return (false);
	}
	return (true);
}
