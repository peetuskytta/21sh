/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:08:12 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 13:47:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strnstr(const char *stack, const char *ndle, size_t i)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (ndle[j] == '\0')
		return ((char *)&stack[0]);
	while (stack[j] != '\0' && (j + ft_strlen(ndle)) <= i)
	{
		k = 0;
		while (ndle[k] == stack[j + k])
		{
			k++;
			if (ndle[k] == '\0')
				return ((char *)&stack[j]);
		}
		j++;
	}
	return (NULL);
}
