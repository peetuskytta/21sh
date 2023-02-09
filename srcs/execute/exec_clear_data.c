/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_clear_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:16 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/07 10:16:13 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	exec_clear_data(t_exec *data)
{
	int	i;

	i = 0;
	while (data->args[i] && i < 512)
		ft_memdel((void *)&data->args[i++]);
	if (data->cmd)
		ft_memdel((void *)&data->cmd);
	if (data->redir[0].file != NULL || data->redir[0].file_in != NULL)
	{
		i = 0;
		while (i < 512)
		{
			if (data->redir[i].file)
				ft_strdel((void *)&data->redir[i].file);
			if (data->redir[i].file_in)
				ft_strdel((void *)&data->redir[i].file_in);
			i++;
		}
	}
}
