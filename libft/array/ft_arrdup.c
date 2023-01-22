/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:35:50 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/22 13:29:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	**ft_arrdup(char **arr)
{
	int		rows;
	int		i;
	char	**res;

	rows = 0;
	while (arr[rows] != NULL)
		rows++;
	res = (char **)malloc(sizeof(char *) * (rows + 1));
	if (res == NULL)
		exit (1);
	i = 0;
	while (arr[i] != NULL && i < rows)
	{
		res[i] = ft_strdup(arr[i]);
		if (res[i] == NULL)
			exit (1);
		ft_memdel((void *)&arr[i++]);
	}
	free(arr);
	res[i] = NULL;
	return (res);
}
