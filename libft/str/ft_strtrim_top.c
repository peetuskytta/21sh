/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:51:32 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 15:16:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static size_t	find_start(char const *s, char c)
{
	size_t	start;

	start = 0;
	while (s[start] != '\0')
	{
		if (s[start] == c)
			return (start);
		else
			start++;
	}
	return (ft_strlen(s));
}

char	*ft_strtrim_top(const char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	start = find_start(s, c);
	if (start == ft_strlen(s))
		return (ft_strnew(0));
	end = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (end - start) + 2);
	if (!p)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && end >= start)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	free((void *)s);
	return (p);
}
