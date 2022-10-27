/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:08:47 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 13:47:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int						i;
	unsigned char			*p;
	const unsigned char		*q;

	p = dest;
	q = src;
	if (src < dest)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			p[i] = q[i];
			i--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return ((void *)dest);
}
