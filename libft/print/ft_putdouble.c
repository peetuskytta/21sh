/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:17:13 by zraunio           #+#    #+#             */
/*   Updated: 2021/03/15 13:47:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putdouble(long double f, int decimal)
{
	long double	d;

	d = f - (long)f;
	if (decimal == 0 && (d * 10) > 5)
		f += 1;
	ft_putlong((long)f);
	if (decimal == 0)
		return ;
	if (decimal >= 20)
		decimal = 19;
	f -= (long)f;
	if (f < 0)
		f *= -1;
	ft_putchar('.');
	while (decimal-- > 0)
		f *= 10;
	d = f - (long)f;
	if ((d * 10) >= 5)
		f += 1;
	ft_putlong((long)f);
}
