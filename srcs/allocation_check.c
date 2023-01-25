/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 18:17:39 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	allocation_check(void **check)
{
	if (check == NULL)
	{
		(void)write(STDERR_FILENO, "unable to allocate memory", 26);
		exit(MALLOC_ERRNO);
	}
}
