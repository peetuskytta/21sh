/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:22:03 by zraunio           #+#    #+#             */
/*   Updated: 2021/05/18 15:16:59 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

/*
** Add a new node to a binary tree.
** < and > can check if node is higher or lower in hierarchy
*/

void	ft_add_node(t_bitree **root, t_bitree *node)
{
	t_bitree	*temp;

	temp = *root;
	if (temp == NULL)
	{
		temp = node;
		*root = temp;
	}
	else if (ft_strcmp(node->item, temp->item) <= 0)
		ft_add_node(&(temp->left), node);
	else
		ft_add_node(&(temp->right), node);
}
