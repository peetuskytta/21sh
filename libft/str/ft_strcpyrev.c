/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:49:21 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/14 14:50:15 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_strcpyrev(char *cmd, char *rev, int max, int n)
{
	int		i;
	int		j;

	i = ft_strlen(cmd) - 1;
	j = ft_strlen(rev);
	if (i < 0 || j >= max)
		return ;
	while (n-- > 0)
		rev[j++] = cmd[i++];
	rev[j] = '\0';
}
