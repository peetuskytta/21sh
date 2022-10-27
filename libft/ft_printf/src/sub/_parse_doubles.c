/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_doubles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:59 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:19:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

static size_t	get_int_part_len(char *value_str)
{
	size_t	len;

	len = 0;
	while (value_str[len] != '.' && value_str[len] != '\0')
		len++;
	if (value_str[0] == '-')
		len--;
	return (len);
}

char	*parse_double_result(t_print *specs, char *value_str, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	i += _add_prefix(specs, &result[i]);
	if (specs->min_field_width > 0 && specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, '0', &result[i]);
	i += _add_number(specs, value_str, &result[i]);
	if (specs->precision == 0 && specs->alt_form)
		result[i++] = '.';
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

size_t	get_result_length(t_print *specs, double value, char *value_str)
{
	size_t	len;

	if (is_nan(value) || is_posinf(value) || is_neginf(value))
		len = 3;
	else
	{
		len = get_int_part_len(value_str);
		if ((specs->precision == 0 && specs->alt_form) || specs->precision != 0)
			len++;
		len += specs->precision;
	}
	if (specs->is_negative)
		len++;
	else if (!specs->is_negative
		&& (specs->plus_signed || specs->blank_signed) && !is_nan(value))
		len++;
	return (len);
}

static void	update_double_specs(t_print *specs, double value)
{
	if (!specs->has_precision)
		specs->precision = 6;
	specs->is_negative = is_neg(value);
	if (is_nan(value) || is_posinf(value) || is_neginf(value))
	{
		specs->precision = 0;
		specs->alt_form = 0;
		specs->zero_padding = 0;
	}
	if (is_nan(value))
	{
		specs->plus_signed = 0;
		specs->blank_signed = 0;
		specs->is_negative = 0;
	}
}

int	_parse_doubles(t_print *specs, va_list *ap, char **result)
{
	double		value;
	char		*value_str;
	size_t		len;

	if (specs->length_modifier[0] == '\0' || specs->length_modifier[0] == 'l')
		value = va_arg(*ap, double);
	else
		value = (double)va_arg(*ap, long double);
	update_double_specs(specs, value);
	value_str = _dtoa(value, specs->precision);
	if (value_str == NULL)
		return (-1);
	len = get_result_length(specs, value, value_str);
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	len += specs->min_field_width;
	*result = parse_double_result(specs, value_str, len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return ((int)len);
}
