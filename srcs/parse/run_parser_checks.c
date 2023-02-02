/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:18 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/02 21:19:12 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	check_next_type(t_tok *next)
{
	if (next == NULL || next->str == NULL
		|| next->type == ';' || next->type == '|')
	{
		ft_perror(SYNTAX_ERR_NL);
		return (true);
	}
	if (next->type != ';' && next->type != '|')
		next->type = REDIR;
	return (false);
}

static bool	redir_inout_errors(t_tok *first)
{
	t_tok	*temp;

	temp = first;
	while (temp != NULL)
	{
		if (ft_strequ(">&", temp->str))
		{
			if (check_next_type(temp->next))
				return (true);
			temp->agre = 1;
			return (false);
		}
		temp = temp->next;
	}
	return (false);
}

bool	run_parser_checks(t_tok *first)
{
	t_tok	*temp;

	temp = first;
	if (redir_inout_errors(first))
		return (true);
	if (redir_checks(temp))
		return (true);
	if (separator_checks(&temp))
		return (true);
	return (false);
}
