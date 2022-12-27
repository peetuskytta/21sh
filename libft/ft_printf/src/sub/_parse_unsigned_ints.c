/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_unsigned_ints.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:20:37 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:20:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

static char	*get_value_string(t_print *specs, uintmax_t value)
{
	char	*result;

	if (specs->conversion == 'o')
		result = _uintmax_itoa_base(value, 8, 0);
	else if (specs->conversion == 'u')
		result = _uintmax_itoa_base(value, 10, 0);
	else if (specs->conversion == 'x')
		result = _uintmax_itoa_base(value, 16, 0);
	else
		result = _uintmax_itoa_base(value, 16, 1);
	return (result);
}

static uintmax_t	get_unsigned_arg(t_print *specs, va_list *ap)
{
	uintmax_t	value;

	if (ft_strcmp(specs->length_modifier, "hh") == 0)
		value = (unsigned char)va_arg(*ap, unsigned int);
	else if (ft_strcmp(specs->length_modifier, "h") == 0)
		value = (unsigned short)va_arg(*ap, unsigned int);
	else if (ft_strcmp(specs->length_modifier, "ll") == 0)
		value = va_arg(*ap, unsigned long long);
	else if (ft_strcmp(specs->length_modifier, "l") == 0)
		value = va_arg(*ap, unsigned long);
	else
		value = (uintmax_t)va_arg(*ap, unsigned int);
	return (value);
}

static size_t	update_uint_specs(t_print *specs,
	uintmax_t value, char *value_str)
{
	size_t	len;

	if (value == 0)
		specs->is_zero = 1;
	if (specs->has_precision)
		specs->zero_padding = 0;
	len = ft_strlen(value_str);
	if (specs->is_zero && specs->zero_precision)
		len = 0;
	if (specs->precision > len)
		specs->precision = specs->precision - len;
	else
		specs->precision = 0;
	if (specs->alt_form && specs->conversion == 'o' && specs->precision == 0
		&& (!specs->is_zero || specs->zero_precision))
		specs->precision++;
	len += specs->precision;
	if (specs->alt_form && ft_strchr("xX", specs->conversion)
		&& !specs->is_zero)
		len += 2;
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	return (len + specs->min_field_width);
}

int	_parse_unsigned_ints(t_print *specs, va_list *ap, char **result)
{
	uintmax_t	value;
	char		*value_str;
	size_t		len;

	value = get_unsigned_arg(specs, ap);
	value_str = get_value_string(specs, value);
	if (value_str == NULL)
		return (-1);
	len = update_uint_specs(specs, value, value_str);
	*result = _parse_int_result(specs, value_str, len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return ((int)len);
}
