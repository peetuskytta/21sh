/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:53 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:18:54 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

static int	parse_conversion(t_print *specs, va_list *ap, char **result)
{
	int	ret;

	if (specs->star)
		specs->min_field_width = (size_t)va_arg(*ap, int);
	if (specs->conversion == '%')
		ret = _parse_char(specs, '%', result);
	else if (specs->conversion == 'c')
		ret = _parse_char(specs, (char)va_arg(*ap, int), result);
	else if (specs->conversion == 's')
		ret = _parse_string(specs, va_arg(*ap, char *), result);
	else if (specs->conversion == 'p')
		ret = _parse_pointer(specs, va_arg(*ap, void *), result);
	else if (ft_strchr("di", specs->conversion))
		ret = _parse_signed_ints(specs, ap, result);
	else if (ft_strchr("ouxX", specs->conversion))
		ret = _parse_unsigned_ints(specs, ap, result);
	else if (ft_strchr("fF", specs->conversion))
		ret = _parse_doubles(specs, ap, result);
	else
		ret = -1;
	return (ret);
}

static int	append_to_result(char **result, int len, int ret, const char *str)
{
	static size_t	arr_size = 100;

	if (*result == NULL)
	{
		*result = ft_memalloc(arr_size + 1);
		if (*result == NULL)
			return (-1);
	}
	if ((size_t)(ret + len) > arr_size)
	{
		*result = _realloc(*result, arr_size, arr_size * 2 + (size_t)ret + 1);
		if (*result == NULL)
			return (-1);
		arr_size = arr_size * 2 + (size_t)ret;
	}
	ft_memcpy(&(*result)[len], str, (size_t)ret);
	return (ret);
}

static int	parse_next_item(
	const char *format,
	va_list *ap,
	char **result,
	int len)
{
	t_print	conversion_specs;
	char	*conversion;
	int		ret;

	conversion = NULL;
	if (*format == '%')
	{
		ft_memset((void *)&conversion_specs, 0, sizeof(t_print));
		_get_conversion_specs(&conversion_specs, format + 1);
		ret = parse_conversion(&conversion_specs, ap, &conversion);
		if (ret == -1)
			return (-1);
		ret = append_to_result(result, len, ret, conversion);
		ft_strdel(&conversion);
	}
	else
		ret = append_to_result(result, len, 1, format);
	return (ret);
}

static int	format_item_length(const char *format)
{
	t_print	conversion_specs;
	int		i;

	i = 0;
	if (format[i] == '%')
		i = _get_conversion_specs(&conversion_specs, &format[i + 1]) + 1;
	else
		i = 1;
	return (i);
}

int	_parse(const char *format, va_list *ap, char **result)
{
	int		i;
	int		len;
	int		ret;

	i = 0;
	len = 0;
	ret = 0;
	while (format[i])
	{
		ret = parse_next_item(&format[i], ap, result, len);
		if (ret == -1)
			break ;
		len += ret;
		i += format_item_length(&format[i]);
	}
	if (ret == -1)
		return (-1);
	if (i == 0)
		*result = ft_strdup("");
	return (len);
}
