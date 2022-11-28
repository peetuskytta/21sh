/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:36:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 13:47:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

size_t	ft_strstr_start(const char *haystack, const char *needle)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (needle[j] == '\0')
		return (ft_strlen(haystack));
	while (haystack[j])
	{
		k = 0;
		while (needle[k])
		{
			if (haystack[j] == needle[k])
				return (j);
			else
				k++;
		}
		j++;
	}
	return (0);
}
