/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:57:22 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/24 13:42:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_print_bits(size_t nb, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((nb >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}
