/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:07 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/03 15:36:55 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	allocation_check(void **check)
{
	if (check == NULL)
	{
		write(STDERR_FILENO, "unable to allocate memory", 26);
		exit(MALLOC_ERRNO);
	}
}

// make into ft_mem style function and add to libft
