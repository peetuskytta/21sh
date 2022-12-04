/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_strcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:25:27 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/04 11:09:08 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_array_strcmp(int *array, char *str)
{
	size_t	i;

	i = 0;
	while (array[i] && str[i] && str[i] == array[i])
		i++;
	return (str[i] - array[i]);
}
