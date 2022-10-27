/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:37:55 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 15:07:21 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strdup(const char *src)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	if (!src)
		return (NULL);
	return (str);
}
