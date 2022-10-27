/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:20:47 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/17 16:06:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strcdup(char *str, char c)
{
	size_t		i;

	i = 0;
	if (c == '\0')
		return (ft_strdup(str));
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (ft_strndup(str, i));
		i++;
	}
	return (NULL);
}
