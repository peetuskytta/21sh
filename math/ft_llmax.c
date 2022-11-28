/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:07:28 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:57:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

long long int	ft_llmax(long long x, long long y)
{
	if (x > y)
		return (x);
	else if (y > x)
		return (y);
	else
		return (x);
}
