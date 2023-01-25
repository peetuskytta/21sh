/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_strip_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:32 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 16:49:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	strip_quotes(t_tok *tok)
{
	int		start;
	int		end;
	char	*temp;

	start = 1;
	end = ft_strilen(tok->str) - 1;
	temp = ft_strsub(tok->str, 1, end - start);
	ft_memdel((void *)&tok->str);
	tok->str = ft_strdup(temp);
	ft_memdel((void *)&temp);
}

void	input_strip_quotes(t_tok **first)
{
	t_tok	*temp;

	temp = *first;
	while (temp != NULL)
	{
		if ((temp->str[0] == '\'' || temp->str[0] == '\"')
			&& temp->str[1] != '\0')
			strip_quotes(temp);
		temp = temp->next;
	}
}
