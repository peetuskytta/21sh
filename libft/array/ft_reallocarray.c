/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:11:52 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 12:41:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	**ft_reallocarray(char **old_arr, int rows)
{
	char	**new_arr;
	int		y;

	new_arr = (char **)malloc(sizeof(char *) * (rows + 1));
	y = 0;
	// ft_memset(new_arr, '\0', sizeof(char *) * (rows + 1));
	while (old_arr[y] != NULL && y < rows)
	{
		new_arr[y] = ft_strdup(old_arr[y]);
		ft_memdel((void *)&old_arr[y++]);
	}
	free(old_arr);
	return (new_arr);
}
