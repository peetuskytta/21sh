/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orfill_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:10:16 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 15:22:20 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

size_t	ft_orfill_bit(size_t nb, size_t *arr)
{
	size_t	i;

	i = 0;
	nb = nb ^ 0x0;
	while (arr[i] != 0)
		nb |= (size_t)arr[i++];
	return (nb);
}
/*
**     f sdfh adds bits using | operator
** int array last value MUST be 0;
*/
