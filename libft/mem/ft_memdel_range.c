/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:36:50 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/25 10:40:41 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memdel_range(const int nbr, ...)
{
	va_list	args;
	char	*str;
	int		i;

	i = nbr;
	va_start(args, nbr);
	while (i--)
	{
		str = va_arg(args, char *);
		ft_strdel(&str);
		str = NULL;
	}
	if (str != NULL)
		exit (EXIT_FAILURE);
	va_end(args);
	return (1);
}
