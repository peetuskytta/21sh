/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _uintmax_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:21:10 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:21:11 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

uintmax_t	_uintmax_pow(int base, int power)
{
	uintmax_t	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}
