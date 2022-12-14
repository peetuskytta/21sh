/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:19:51 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:19:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

static char	*parse_str_result(t_print *specs, char *str, size_t str_len)
{
	size_t	result_len;
	size_t	i;
	size_t	j;
	char	*result;

	result_len = str_len + specs->min_field_width;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	else if (specs->min_field_width > 0 && specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, '0', &result[i]);
	j = 0;
	while (j < str_len)
		result[i++] = str[j++];
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

static size_t	update_str_specs(t_print *specs, char *str)
{
	size_t	len;

	if (str == NULL)
	{
		if (specs->has_precision && specs->precision < 6)
			len = specs->precision;
		else
			len = 6;
	}
	else
	{
		len = ft_strlen(str);
		if (specs->has_precision && specs->precision < len)
			len = specs->precision;
	}
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	return (len);
}

int	_parse_string(t_print *specs, char *str, char **result)
{
	size_t	str_len;

	str_len = update_str_specs(specs, str);
	if (str == NULL)
		*result = parse_str_result(specs, "(null)", str_len);
	else
		*result = parse_str_result(specs, str, str_len);
	if (*result == NULL)
		return (-1);
	else
		return ((int)ft_strlen(*result));
}

int	_parse_char(t_print *specs, char c, char **result)
{
	if (specs->min_field_width >= 1)
		specs->min_field_width--;
	*result = parse_str_result(specs, &c, 1);
	if (*result == NULL)
		return (-1);
	return ((int)specs->min_field_width + 1);
}
