/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:02:52 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:52:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_lutoa(unsigned long int nb)
{
	char	*res;
	int		len;

	len = ft_count_digit(nb);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	while (nb != 0 && len >= 0)
	{
		res[len-- - 1] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (res);
}
