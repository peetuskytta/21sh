/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rounds_half_to_even.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:20:49 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:20:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

static int	has_exact_fraction(double nbr, int precision, double div)
{
	double		int_part;
	double		frac_part;
	uintmax_t	integral_frac;

	frac_part = _modf(_fabs(nbr), &int_part);
	integral_frac = (uintmax_t)(frac_part * div * 10);
	if (integral_frac % _uintmax_pow(5, precision + 1) == 0)
		return (1);
	else
		return (0);
}

int	_rounds_half_to_even(double nbr, int precision)
{
	double	div;

	div = _dpow(10.0, precision);
	if (_fabs(nbr * div) - (uintmax_t)_fabs(nbr * div) != 0.5)
		return (0);
	if (has_exact_fraction(nbr, precision, div))
		return (1);
	else
		return (0);
}
