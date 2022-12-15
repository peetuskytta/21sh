/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:55:46 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:51:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_litoa(long long int n)
{
	int		num;
	char	*s;

	num = ft_count_digit(n);
	s = (char *)malloc(sizeof(char) * num + 1);
	if (!s)
		return (NULL);
	s = ft_memset(s, 0, num + 1);
	if (n < 0)
	{
		s[0] = '-';
		if (n == -9223372036854775807 - 1)
			n = -9223372036854775807;
		n *= -1;
	}
	s[num--] = '\0';
	while (num >= 0 && s[num] != '-')
	{
		s[num--] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (s);
}
