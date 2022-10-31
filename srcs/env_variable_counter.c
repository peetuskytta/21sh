/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable_counter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:48:05 by pskytta           #+#    #+#             */
/*   Updated: 2022/10/31 14:48:24 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/shell.h"

int	env_variable_counter(char **environ)
{
	int	count;

	count = 0;
	while (environ[count] != NULL)
		count++;
	return (count);
}
