/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:39:31 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/03 10:50:43 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	close_fds(int fd_in, int fd_out)
{
	if (fd_in >= 0)
	{
		//ft_putnbr_endl(fd_in);
		close(fd_in);
	}
	if (fd_out >= 0)
	{
		//ft_putnbr_endl(fd_out);
		close(fd_out);
	}
}
