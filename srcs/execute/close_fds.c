/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:39:31 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/29 17:40:17 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	close_fds(int fd_in, int fd_out)
{
	if (fd_in > 0)
		close(fd_in);
	if (fd_out > 0)
		close(fd_out);
}
