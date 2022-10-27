/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 08:54:50 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:16:28 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_realloc(void *ptr, size_t o_size, size_t n_size)
{
	void	*dest;
	size_t	i;

	if (ptr && n_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	dest = (void *)malloc(n_size);
	if (dest && ptr)
	{
		if (o_size > n_size)
			i = n_size;
		else
			i = o_size;
		ft_memcpy(dest, ptr, i);
		if (n_size > o_size)
			ft_memset((void *)(&((char *)dest)[o_size]), 0, n_size - o_size);
		free(ptr);
	}
	return ((void *)dest);
}
