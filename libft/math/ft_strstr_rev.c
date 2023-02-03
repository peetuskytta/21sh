/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:40:02 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/03 16:40:30 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_strstr_rev(const char *haystack, const char *needle)
{
	int	j;
	int	k;

	j = ft_strilen(haystack) - 1;
	if (j == 0)
		return (-1);
	while (j >= 0)
	{
		k = ft_strilen(needle) - 1;
		while (k >= 0)
		{
			if (haystack[j] == needle[k])
				return (j);
			else
				k--;
		}
		j--;
	}
	return (-1);
}
