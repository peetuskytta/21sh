/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:15:33 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 15:46:39 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	clear_data(t_exec *data)
{
	int	i;

	i = 0;
	while (data->args[i])
	{
		ft_strdel((void *)&data->args[i]);
		i++;
	}
	if (data->redir[0].file != NULL)
	{
		i = 0;
		while (data->redir[i].file != NULL)
		{
			ft_strdel((void *)&data->redir[i].file);
			data->redir[i].aggr = -1;
			data->redir[i].type = -1;
			data->redir[i++].fildes = -1;
		}
	}
}

void	cmd_redir_execute(t_exec data, char **path, char **env_cpy)
{
	clear_data(&data);
	//ft_strdel((void *)&data.redir->file);
	(void)path;
	(void)env_cpy;
}