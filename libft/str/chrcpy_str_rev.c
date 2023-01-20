/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrcpy_str_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:56:39 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/16 12:37:34 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	chrcpy_str_rev(char *cmd, char *rev, int max, int n)
{
	int		i;
	int		j;

	i = ft_strlen(cmd) - 1;
	j = ft_strlen(rev);
	if (i < 0 || j >= max || i == max || i + j > max)
		return (-1);
	while (n-- > 0)
	{
		rev[j++] = cmd[i];
		cmd[i--] = '\0';
	}
	rev[j] = '\0';
	return (0);
}
