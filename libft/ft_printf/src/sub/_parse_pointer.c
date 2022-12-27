/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:19:06 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:19:07 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

int	_parse_pointer(t_print *specs, void *ptr, char **result)
{
	uintmax_t	value;
	char		*value_str;
	size_t		result_len;

	value = (uintmax_t)ptr;
	value_str = _uintmax_itoa_base(value, 16, 0);
	if (value_str == NULL)
		return (-1);
	result_len = ft_strlen(value_str) + 2;
	specs->conversion = 'x';
	specs->alt_form = 1;
	specs->has_precision = 0;
	specs->precision = 0;
	if (specs->min_field_width > result_len)
		specs->min_field_width = specs->min_field_width - result_len;
	else
		specs->min_field_width = 0;
	result_len += specs->min_field_width;
	*result = _parse_int_result(specs, value_str, result_len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return ((int)result_len);
}
