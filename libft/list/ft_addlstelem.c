/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlstelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:43:58 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 14:55:29 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_addlstelem(t_list *lst, char *str)
{
	char	**tmp;

	if (!str)
		return (0);
	if (lst->elem_count == lst->arg_size)
	{
		tmp = (char **)malloc(sizeof(char *) * lst->arg_size * 2);
		if (!tmp)
			return (0);
		tmp = ft_memcpy(tmp, lst->arg, sizeof(char *) * lst->arg_size);
		free(lst->arg);
		lst->arg = tmp;
		lst->arg_size *= 2;
	}
	lst->arg[lst->elem_count] = ft_strnew(ft_strlen(str));
	lst->arg[lst->elem_count] = ft_strdup(str);
	lst->elem_count++;
	return (1);
}
