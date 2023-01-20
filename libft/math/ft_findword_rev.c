/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findword_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:07:51 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/20 09:09:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_finword_rev(char *str)
{
	int	i;

	i = ft_strilen(str) - 1;
	if (i <= 1)
	{
		if (i == -1 || i == 0)
			return (0);
		else
			return (1);
	}
	while (ft_isspace(str[i]) && i > 0)
		i--;
	while (!ft_isspace(str[i]) && i > 0)
		i--;
	if (i == 0 || i == 1)
		return (i);
	return (i + 1);
}
