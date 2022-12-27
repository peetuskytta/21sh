/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:24:23 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:52:29 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static int	ft_base(unsigned long long int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*ft_lutoa_base(unsigned long long int nb, long int base)
{
	int							i;
	char						*res;
	long long int				tmp;

	i = 0;
	tmp = nb;
	while (tmp >= base)
		tmp = tmp / base;
	i = dig_count_base(nb, base);
	res = ft_strnew(i + 1);
	while (i >= 0)
	{
		tmp = nb % base;
		res[i] = ft_base(tmp);
		nb = nb / base;
		i--;
	}
	return (res);
}
