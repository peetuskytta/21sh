/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_clear_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:16 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/05 15:26:38 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	exec_clear_data(t_exec *data, char *path)
{
	int	i;

	i = 0;
	while (data->args[i])
		ft_strdel((void *)&data->args[i++]);
	if (path)
		ft_strdel((void *)&path);
	if (data->cmd)
		ft_strdel((void *)&data->cmd);
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
}
