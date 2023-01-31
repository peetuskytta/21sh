/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregation_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:13:39 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 15:30:49 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

/* static bool	aggr_checks(t_tok *tok, t_tok *next)
{
	if (ft_strequ(">&", tok->str) || ft_strequ(">&-", tok->str)
		|| ft_strequ("1>&-", tok->str) || ft_strequ("2>&-", tok->str)
		|| ft_strequ("1>&2", tok->str) || ft_strequ("2>&1", tok->str))
	{
		if (next->type != CHAR_SEMICOLON || next->type != CHAR_PIPE)
		{
			if (ft_strequ(">&", tok->str))
				next->type = WORD;
		}
		tok->agre = 1;
	}
	else if (ft_strequ("0<&-", tok->str))
	{
		ft_perror(BAD_FD);
		ft_perror("0<&-\n");
		return (true);
	}
	else
	{
		ft_perror(PARSE_ERR);
		ft_print_fd(STDERR_FILENO, "%s'\n", tok->str);
		return (true);
	}
	if (ft_strequ(">&", tok->str) && (next->str == NULL || next->str[0] == '\0'
			|| ft_strequ(next->str, " ") || next->type == CHAR_SEMICOLON || next->type == CHAR_PIPE))
	{
		ft_perror(SYNTAX_ERR);
		return (true);
	}
	return (false);
} */

bool	aggregation_checks(t_tok *temp)
{
	(void)temp;
/*  	if (aggr_checks(temp));
		return (true); */
	return (false);
}