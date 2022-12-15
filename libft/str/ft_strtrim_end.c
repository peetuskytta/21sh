/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:40:50 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 15:16:06 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static size_t	find_end(char const *s, char c)
{
	size_t	end;
	size_t	i;

	i = ft_strlen(s);
	while (s[i] != c || s[i] == '\0')
		i--;
	end = i;
	return (end);
}

char	*ft_strtrim_end(const char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	start = 0;
	if (start == ft_strlen(s))
		return (ft_strnew(0));
	end = find_end(s, c);
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
