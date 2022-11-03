/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:07 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/03 13:26:42 by pskytta          ###   ########.fr       */
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
