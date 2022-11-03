/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:22:23 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/02 10:02:45 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

/*
** str - the string to traverse
** c - the character to locate
** start: 'b' for traversing from 0 and 'e' for traversing from end of str
*/

int	ft_strchr_index(char *str, char c, char start)
{
	size_t	i;

	i = 0;
	if (start == 'b')
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	else if (start == 'e')
	{
		i = ft_strlen(str);
		while (i > 0)
		{
			if (str[i] == c)
				return (i);
			i--;
		}
	}
	return (-1);
}
