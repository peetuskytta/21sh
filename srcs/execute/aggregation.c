/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:44:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 12:44:30 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static void	dup_fds(int aggr_type)
{
	if (aggr_type == AGGR_COPY_ONE)
		dup2(STDERR_FILENO, STDOUT_FILENO);
	else if (aggr_type == AGGR_COPY_TWO)
		dup2(STDOUT_FILENO, STDERR_FILENO);
	else if (aggr_type == AGGR_COPY_BOTH)
		dup2(STDOUT_FILENO, STDERR_FILENO);
}

void	aggregation(t_exec *data)
{
	ft_putnbr_endl(data->redir->agre);
	ft_putnbr_endl(data->redir->type);
	ft_putendl(data->redir->file);
	if (data->redir->agre > 9 && data->redir->agre < 13)
	{
		if (data->redir->agre == AGGR_CLOSE_BOTH)
		{
			close(STDERR_FILENO);
			close(STDOUT_FILENO);
		}
		else if (data->redir->agre == AGGR_CLOSE_ONE)
			close(STDOUT_FILENO);
		else if (data->redir->agre == AGGR_CLOSE_TWO)
			close(STDERR_FILENO);
	}
	else if (data->redir->agre > 12)
		dup_fds(data->redir->agre);
}