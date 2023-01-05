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

static void	clear_redir_data(t_exec *data, char *path)
{
	int	i;

	i = 0;
	while (data->args[i])
		ft_strdel((void *)&data->args[i++]);
	if (data->redir[0].file != NULL)
	{
		i = 0;
		while (data->redir[i].file != NULL)
		{
			ft_strdel((void *)&data->redir[i].file);
			data->redir[i].type = -1;
			data->redir[i++].fildes = -1;
		}
	}
	if (path)
		ft_strdel((void *)&path);
	if (data->cmd)
		ft_strdel((void *)&data->cmd);
}

static void	execute_redir(t_exec data, char *bin_path, char **env_cpy)
{
	redir_start(&data);
	(void)data;
	(void)env_cpy;
	(void)bin_path;
}

void	exec_cmd_redir(t_exec data, char **env_cpy)
{
	char	*bin_path;

	bin_path = exec_find_binary(exec_fetch_path_var(env_cpy), data.cmd);
	if (exec_binary_check(bin_path, data.cmd))
		execute_redir(data, bin_path, env_cpy);
	clear_redir_data(&data, bin_path);

}