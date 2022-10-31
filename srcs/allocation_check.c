/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:49:07 by pskytta           #+#    #+#             */
/*   Updated: 2022/10/31 14:50:03 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/shell.h"

void	allocation_check(void **check)
{
	if (check == NULL)
	{
		write(STDERR_FILENO, "unable to allocate memory", 26);
		exit(5);
	}
}
