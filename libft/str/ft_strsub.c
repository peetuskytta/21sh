/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:43:34 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 15:14:21 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	d = (char *)malloc(sizeof(*s) * (len + 1));
	if (!d)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}
