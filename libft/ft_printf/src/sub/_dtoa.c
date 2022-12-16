/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dtoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:32 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:18:35 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

static int	int_part_len(long double nbr)
{
	int	len;

	len = 1;
	while ((nbr > 0 && nbr / 10 >= 1.0) || (nbr < 0 && nbr / 10 <= -1.0))
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int	add_integral_part(char *result, double int_part, int len)
{
	int		i;
	int		j;
	double	dbl_tmp;
	double	res;
	int		int_tmp;

	i = 0;
	if (is_neg(int_part))
		result[i++] = '-';
	int_part = _fabs(int_part);
	while (len > 0)
	{
		dbl_tmp = int_part;
		j = 0;
		while (++j < len)
			dbl_tmp /= 10;
		int_tmp = (int)dbl_tmp;
		result[i++] = (char)int_tmp + '0';
		len--;
		res = _dpow(10.0, len);
		res *= (double)int_tmp;
		int_part -= res;
	}
	return (i);
}

static int	add_fractional_part(char *result, long double frac_part,
size_t precision)
{
	int			i;

	if (precision == 0)
		return (0);
	frac_part = _fabsl(frac_part);
	i = 0;
	while (result[i])
		i++;
	result[i++] = '.';
	while (precision-- > 0)
	{
		frac_part *= 10;
		result[i++] = (char)frac_part + '0';
		frac_part -= (int)frac_part;
	}
	return (i);
}

static int	result_len(double int_part, size_t precision)
{
	int	len;

	len = int_part_len(int_part);
	if (is_neg(int_part))
		len++;
	len += (int)precision;
	if (precision > 0)
		len++;
	return (len);
}

char	*_dtoa(double nbr, size_t precision)
{
	char		*result;
	double		int_part;
	long double	frac_part;

	if (is_nan(nbr))
		return (ft_strdup("nan"));
	else if (is_posinf(nbr))
		return (ft_strdup("inf"));
	else if (is_neginf(nbr))
		return (ft_strdup("-inf"));
	frac_part = _round_double(_modf(nbr, &int_part), precision);
	if (frac_part >= 1.0 || frac_part <= -1)
	{
		int_part += (int)frac_part;
		frac_part -= (int)frac_part;
	}
	else if (_rounds_half_to_even(nbr, (int)precision)
		&& (uintmax_t)(_fabs(int_part) + 1) % 2 == 0)
		int_part += is_neg(nbr) * -1.0 + (1 - is_neg(nbr)) * 1.0;
	result = (char *)ft_memalloc((size_t)result_len(int_part, precision) + 1);
	if (result == NULL)
		return (NULL);
	add_integral_part(result, int_part, int_part_len(int_part));
	add_fractional_part(result, frac_part, precision);
	return (result);
}
