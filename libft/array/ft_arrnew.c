/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:00:33 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/15 11:50:55 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	**ft_arrnew(size_t rows, size_t row_len)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (rows + 1));
	if (arr == NULL)
		exit (1);
	arr[0] = (char *)malloc(sizeof(char) * (row_len + 1));
	if (arr[0] == NULL)
		exit(1);
	while (arr[rows])
		ft_bzero((void *)arr[rows--], row_len);
	return (arr);
}
