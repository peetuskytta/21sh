/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_ignore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:00:00 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 15:00:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	signal_ignore(void)
{
	int	i;

	i = 1;
	while (i < 32)
	{
		signal(i, SIG_IGN);
		i++;
	}
	signal(SIGTSTP, SIG_IGN);
}
