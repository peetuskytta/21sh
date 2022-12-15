/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:23:58 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/24 13:24:29 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_arrtrim(char **arr, size_t row)
{
	while (arr[row + 1] != NULL)
	{
		ft_memdel((void *)&arr[row]);
		arr[row] = ft_strnew(ft_strilen(arr[row + 1]));
		ft_strcpy(arr[row], arr[row +1]);
		row++;
	}
	ft_memdel((void *)&arr[row]);
}
