/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:22:36 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:59:32 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while ((unsigned char *)s1 && (unsigned char *)s2
		&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && --n)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	else
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
