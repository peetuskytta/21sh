/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:08:37 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/06 17:26:22 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strtrimdup(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			return (ft_strndup(str, i));
		i++;
	}
	return (NULL);
}
