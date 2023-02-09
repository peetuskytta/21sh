/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_strip_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:32 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/06 13:22:40 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	strip_quotes(t_tok *tok, char q)
{
	int		start;
	int		end;
	char	*temp;
	char	*top;

	top = NULL;
	start = ft_strchr_index(tok->str, q, 'b');
	if (start != 0)
		top = ft_strsub(tok->str, 0, start);
	end = start + 1;
	while (tok->str[end] != q && tok->str[end] != '\0')
		end++;
	temp = ft_strsub(tok->str, start + 1, end - start - 1);
	if (top != NULL)
		temp = ft_strjoin_free(top, temp, 3);
	if (tok->str[end + 1] != '\0' && tok->str[end + 1] != q)
		temp = ft_strjoin_free(temp, &tok->str[end + 1], 1);
	ft_memdel((void *)&tok->str);
	tok->str = ft_strdup(temp);
	ft_memdel((void *)&temp);
}

void	input_strip_quotes(t_tok **first)
{
	t_tok	*temp;
	char	q;

	temp = *first;
	while (temp != NULL)
	{
		q = 0;
		if (ft_strchr(temp->str, '\'') && temp->str[1] != '\0')
			q = '\'';
		else if (ft_strchr(temp->str, '\"') && temp->str[1] != '\0')
			q = '\"';
		if (q == '\'' || q == '\"')
			strip_quotes(temp, q);
		temp = temp->next;
	}
}
