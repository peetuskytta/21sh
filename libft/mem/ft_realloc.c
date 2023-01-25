/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 08:54:50 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 13:34:29 by zraunio          ###   ########.fr       */
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
		new = (void *)malloc(new_size);
	if (new != NULL && ptr != NULL)
	{
		if (old_size > new_size)
			ft_memcpy(new, ptr, new_size);
		else
			ft_memcpy(new, ptr, old_size);
		if (new_size > old_size)
			ft_memset(&new, 0, new_size - old_size);
		free(ptr);
	}
	return (new);
}

/*
** norm errors, ternanries forbidden, change it
*/