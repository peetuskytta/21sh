/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:32:28 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:51:14 by zraunio          ###   ########.fr       */
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

char	*ft_itoa_base(long long int nb, long int base)
{
	int					i;
	int					flg;
	char				*res;
	long long int		tmp;

	i = 0;
	tmp = nb;
	flg = 0;
	while (tmp >= base)
		tmp = tmp / base;
	i = dig_count_base(nb, base);
	if (nb < 0)
		flg = 1;
	res = ft_strnew(i + 1);
	if (!res)
		return (NULL);
	res[i + 1] = '\0';
	while (i >= flg)
	{
		tmp = nb % base;
		res[i] = ft_base(tmp);
		nb = nb / base;
		i--;
	}
	return (res);
}
