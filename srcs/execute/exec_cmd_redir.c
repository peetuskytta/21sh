/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:15:33 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/03 17:38:02 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	redirection_start(t_exec data, char *bin_path, char **env_cpy)
{
	redirection_loop(&data);
	(void)env_cpy;
	(void)bin_path;
}

void	exec_cmd_redir(t_exec data, char **env_cpy)
{
	char	*bin_path;

	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data.cmd);
	if (exec_binary_check(bin_path, data.cmd))
		redirection_start(data, bin_path, env_cpy);
	exec_clear_data(&data, bin_path);
}