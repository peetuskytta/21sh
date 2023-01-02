/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:15:33 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 12:16:12 by pskytta          ###   ########.fr       */
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
	if (data->redir->file != NULL)
	{
		ft_strdel((void *)&data->redir->file);
		data->redir->aggr = -1;
		data->redir->type = -1;
		data->redir->fildes = -1;
	}
}

void	cmd_redir_execute(t_exec data, char **path)
{
	clear_data(&data);
	//ft_strdel((void *)&data.redir->file);
	(void)path;
}