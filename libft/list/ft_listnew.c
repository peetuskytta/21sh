/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:39:41 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/14 12:47:49 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_listnew(size_t size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->arg = (char **)malloc(sizeof(char *) * size);
	if (!lst->arg)
		return (NULL);
	ft_memset(lst->arg, 0, size);
	lst->arg_size = size;
	lst->elem_count = 0;
	return (lst);
}
