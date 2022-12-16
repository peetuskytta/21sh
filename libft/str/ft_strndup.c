/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:16:38 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/26 14:16:39 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (n >= len)
		n = len;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		exit (1);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
