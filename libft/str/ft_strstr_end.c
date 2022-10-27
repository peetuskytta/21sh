/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:01:38 by zraunio           #+#    #+#             */
/*   Updated: 2022/06/21 16:26:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strstr_end(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i + x] == needle[x])
		{
			x++;
			if (x == ft_strlen(needle))
				return ((char *)haystack + i + x);
		}
		i++;
		x = 0;
	}
	return (NULL);
}
