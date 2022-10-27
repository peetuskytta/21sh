/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:58:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:53:41 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static int	ft_base(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*ft_utoa_base(unsigned long int nb, long int base)
{
	int						i;
	char					*res;
	long long int			tmp;

	i = 0;
	tmp = nb;
	while (tmp >= base)
		tmp = tmp / base;
	i = dig_count_base(nb, base);
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i >= 0)
	{
		tmp = nb % base;
		res[i] = ft_base(tmp);
		nb = nb / base;
		i--;
	}
	return (res);
}
