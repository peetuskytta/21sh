/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:20:06 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:20:07 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

size_t	_add_number(t_print *specs, char *number, char *result)
{
	size_t	i;

	i = 0;
	if (specs->is_negative)
		number++;
	while (number[i])
	{
		result[i] = number[i];
		i++;
	}
	return (i);
}

size_t	_add_padding(size_t len, char c, char *result)
{
	size_t	i;

	i = 0;
	while (i < len)
		result[i++] = c;
	return (i);
}

size_t	_add_prefix(t_print *specs, char *result)
{
	size_t	i;

	i = 0;
	if (specs->is_negative)
		result[i++] = '-';
	else if (ft_strchr("difF", specs->conversion)
		&& (specs->blank_signed || specs->plus_signed))
	{
		if (specs->plus_signed)
			result[i++] = '+';
		else
			result[i++] = ' ';
	}
	else if (specs->conversion == 'x' && specs->alt_form && !specs->is_zero)
	{
		result[i++] = '0';
		result[i++] = 'x';
	}
	else if (specs->conversion == 'X' && specs->alt_form && !specs->is_zero)
	{
		result[i++] = '0';
		result[i++] = 'X';
	}
	return (i);
}

char	*_parse_int_result(t_print *specs, char *number, size_t result_len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (result_len + 1));
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
	if (specs->precision > 0)
		i += _add_padding(specs->precision, '0', &result[i]);
	if (!(specs->zero_precision && specs->is_zero))
		i += _add_number(specs, number, &result[i]);
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}
