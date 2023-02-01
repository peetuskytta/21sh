/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:17:15 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/01 16:37:43 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	exec_real(t_exec *data, char **env_cpy)
{
	char	*bin_path;

	bin_path = NULL;
	if (!bin_path)
		bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data->cmd);
	if (redirection_loop(data) && exec_binary_check(&bin_path, *data))
		exec_cmd(data, bin_path, env_cpy);
	else
		close_fds(data->fds.fd_in, data->fds.fd_out);
	ft_strdel((void *)&bin_path);
}
