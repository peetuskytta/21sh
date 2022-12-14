/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vasprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:21:21 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:21:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

int	_vasprint(char **ret, const char *format, va_list ap)
{
	int		ret_value;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	*ret = NULL;
	ret_value = _parse(format, &ap_copy, ret);
	va_end(ap_copy);
	return (ret_value);
}
