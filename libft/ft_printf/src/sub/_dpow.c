/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dpow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:18:24 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:18:28 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	_dpow(double base, int power)
{
	double	result;

	result = 1.0;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}
