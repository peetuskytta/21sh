/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_runtime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:10:15 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 15:10:41 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	signal_runtime(void)
{
	int		i;

	i = 1;
	while (i < 32)
	{
		signal(i, SIG_DFL);
		i++;
	}
	signal(SIGTSTP, SIG_IGN);
}
