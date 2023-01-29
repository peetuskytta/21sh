/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:31:36 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/29 17:33:00 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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
		|| ft_strequ("2>", str) || ft_strequ("2>>", str)
		|| ft_strequ("2>>1", str) || ft_strequ("1>>2", str)
		|| ft_strequ("1>2", str) || ft_strequ("2>1", str))
		;
	else if (next->type == REDIR && ft_strchr(next->str, '&'))
	{
		ft_print_fd(2, "\n"AGGR_ERR"\n");
		return (true);
	}
	else
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", str);
		return (true);
	}
	if (redir_validation(next))
		return (true);
	return (false);
}
