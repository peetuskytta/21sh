/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:56:10 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:57:40 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

long long int	ft_powerof(long int nb, unsigned int p)
{
	long long int	tmp;

	tmp = nb;
	if (p == 0)
		return (1);
	while (--p)
		tmp *= nb;
	return (tmp);
}
