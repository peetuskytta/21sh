/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:09:06 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:58:34 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*q;
	unsigned char		chr;

	i = 0;
	p = dest;
	q = src;
	chr = (unsigned char)c;
	while (i < n)
	{
		p[i] = q[i];
		if (q[i] == chr)
			return ((void *)&p[++i]);
		i++;
	}
	return (NULL);
}
