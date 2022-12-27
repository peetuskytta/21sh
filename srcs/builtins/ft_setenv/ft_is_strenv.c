/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_strenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:16:38 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/17 12:17:04 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

int	ft_is_strenv(char *name, char **environ)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strnstr(environ[i], name, ft_strlen(name)) != NULL)
		{
			if (environ[i][(int)ft_strlen(name)] == '=')
				return (i);
		}
		i++;
	}
	return (-1);
}
