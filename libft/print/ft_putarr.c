/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:45:35 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/03 15:50:44 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putarr(char **arr)
{
	int	i;
	int	j;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		j = ft_strlen(arr[i]);
		ft_putendl(arr[i++]);
	}
}
