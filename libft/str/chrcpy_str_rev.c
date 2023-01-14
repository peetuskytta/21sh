/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrcpy_str_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:56:39 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 14:43:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	chrcpy_str_rev(char *cmd, char *rev, int max, int n)
{
	int		i;
	int		j;

	i = ft_strlen(cmd) - 1;
	j = ft_strlen(rev);
	if (i < 0 || j >= max)
		return ;
	while (n-- > 0)
	{
		rev[j++] = cmd[i];
		cmd[i--] = '\0';
	}
	rev[j] = '\0';
}
