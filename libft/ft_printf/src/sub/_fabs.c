/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _fabs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:20:24 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:20:25 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/libft.h"
#include "../inc/print_internal.h"

long double	_fabsl(long double nbr)
{
	if (nbr < 0.0 || nbr == -0.0)
		return (-nbr);
	else
		return (nbr);
}

double	_fabs(double nbr)
{
	if (is_neg(nbr))
		return (-nbr);
	else
		return (nbr);
}
