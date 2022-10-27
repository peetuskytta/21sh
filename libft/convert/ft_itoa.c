/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:46:20 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:49:30 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_itoa(int n)
{
	int		num;
	char	*s;

	num = ft_count_digit(n);
	s = (char *)malloc(sizeof(char) * num + 2);
	if (!s)
		return (NULL);
	s = ft_memset(s, 0, num);
	s[num--] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		if (n == -2147483648)
		{
			s[num--] = '8';
			n = -214748364;
		}
		n *= -1;
	}
	while (num >= 0 && s[num] != '-')
	{
		s[num--] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (s);
}
