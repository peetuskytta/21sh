/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:21:49 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:21:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"

int	is_neg(double n)
{
	uint64_t	double_as_int;
	uint8_t		sign;

	ft_memcpy(&double_as_int, &n, sizeof(n));
	sign = (uint8_t)(double_as_int >> 63);
	if (sign == 0)
		return (0);
	return (1);
}
