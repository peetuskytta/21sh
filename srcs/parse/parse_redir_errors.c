/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:31:36 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 15:52:58 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	redir_validation(t_tok *next)
{
	if (next == NULL)
	{
		ft_perror("syntax error near unexpected token `newline'\n");
		return (true);
	}
	return (false);
}

bool	parse_redir_errors(char *str, t_tok *next)
{
	if (ft_strequ(">", str) || ft_strequ(">>", str)
		||ft_strequ("<", str) || ft_strequ("<<", str)
		|| ft_strequ("1>", str) || ft_strequ("1>>", str)
		|| ft_strequ("2>", str) || ft_strequ("2>>", str))
		;
	else
	{
		if (next->type != '|' && next->type != ';')
		{
			ft_print_fd(2, "\n21sh parse error near `%s'\n", str);
			return (true);
		}
	}
	if (redir_validation(next))
		return (true);
	return (false);
}
