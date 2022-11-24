/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 08:54:50 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/17 15:22:31 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		new = NULL;
	}
	else
		new = (void*)malloc(new_size);
	if (new != NULL && ptr != NULL)
	{
		ft_memcpy(new, ptr, (old_size > new_size ? new_size : old_size));
		if (new_size > old_size)
			ft_memset(&new[old_size], 0, new_size - old_size);
		free(ptr);
	}
	return (new);
}
