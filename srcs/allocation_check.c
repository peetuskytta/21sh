/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/09 12:15:24 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	allocation_check(void **check)
{
	if (check == NULL)
	{
		ft_perror("unable to allocate requested memory\n");
		exit(MALLOC_ERRNO);
	}
}
