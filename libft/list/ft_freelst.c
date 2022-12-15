/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:06:59 by zraunio           #+#    #+#             */
/*   Updated: 2022/09/25 10:25:47 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_freelst(t_list *ls)
{
	ft_arr_free((void *)&ls->arg);
	ls->arg_size = 0;
	ls->elem_count = 0;
	ft_memdel((void *)&ls);
}
