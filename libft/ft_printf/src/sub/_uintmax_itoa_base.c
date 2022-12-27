/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _uintmax_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:20:57 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:21:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

char	*_uintmax_itoa_base(uintmax_t value, int base, int uppercase)
{
	char	*result;
	char	*digits;
	char	temp[64 + 1];
	size_t	i;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	i = 64;
	temp[i--] = '\0';
	if (value == 0)
		temp[i--] = '0';
	while (value != 0)
	{
		temp[i--] = digits[value % (uintmax_t)base];
		value = value / (uintmax_t)base;
	}
	result = (char *)malloc(64 - i + 1);
	if (result == NULL)
		return (NULL);
	return (ft_strcpy(result, &temp[i + 1]));
}
