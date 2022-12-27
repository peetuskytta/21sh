/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:17:18 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:17:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/libft.h"
#include "../inc/print_internal.h"

char	*format(const char *format, ...)
{
	char	*ret;
	va_list	ap;

	va_start(ap, format);
	ret = NULL;
	if (!(_vasprint(&ret, format, ap)))
		return (NULL);
	va_end(ap);
	return (ret);
}
