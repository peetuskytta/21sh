/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:31:36 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/03 16:46:54 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	direction_in(char *str, t_tok *next)
{
	if (next->type != REDIR)
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", str);
		return (true);
	}
	return (false);
}

static bool	direction_out(char *str, t_tok *next)
{
	if (next->type != REDIR)
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", str);
		return (true);
	}
	return (false);
}

bool	parse_redir_errors(char *str, t_tok *next)
{
	if (ft_strequ("<", str) || ft_strequ("<<", str))
		return (direction_in(str, next));
	else if (ft_strequ(">", str) || ft_strequ(">>", str)
		|| ft_strequ("1>", str) || ft_strequ("1>>", str)
		|| ft_strequ("2>", str) || ft_strequ("2>>", str))
		return (direction_out(str, next));
	return (false);
}
