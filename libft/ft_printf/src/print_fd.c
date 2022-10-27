/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:17:46 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/06 16:59:31 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/libft.h"
#include "../inc/print_internal.h"

int	ft_print_fd(int fd, const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = _vasprint(&result, format, ap);
	va_end(ap);
	if (ret != -1)
		ret = write(fd, result, (size_t)ret);
	free(result);
	return (ret);
}
