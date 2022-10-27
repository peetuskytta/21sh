/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:17:26 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:17:30 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/libft.h"
#include "../inc/print_internal.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = _vasprint(&result, format, ap);
	va_end(ap);
	if (ret != -1)
		ret = write(1, result, (size_t)ret);
	free(result);
	return (ret);
}
