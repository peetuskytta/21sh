/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:47:39 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 15:06:09 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
