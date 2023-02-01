/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:13:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 14:17:31 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	in_closed_check(char *str)
{
	if (ft_strchr(str, '0'))
	{
		ft_perror(BAD_FD);
		ft_perror(str);
		ft_putchar('\n');
		return (true);
	}
	return (false);
}

static bool	check_next_type(t_tok *next)
{
	if (next == NULL || next->type == ';' || next->type == '|')
	{
		ft_perror(SYNTAX_ERR_NL);
		return (true);
	}
	if (next->type != ';' && next->type != '|')
		next->type = REDIR;
	return (false);
}

static bool	aggr_checks(t_tok *tok, t_tok *next)
{
	if (ft_strequ(">&-", tok->str) || ft_strequ("1>&-", tok->str)
		|| ft_strequ("2>&-", tok->str) || ft_strequ("1>&2", tok->str)
		|| ft_strequ("2>&1", tok->str))
	{
		if (next->type == REDIR)
			next->type = WORD;
		tok->agre = 1;
	}
	if (ft_strequ(">&", tok->str))
	{
		if (check_next_type(next))
			return (true);
		tok->agre = 1;
		return (false);
	}
	return (in_closed_check(tok->str));
}

bool	redir_checks(t_tok *temp)
{
	while (temp->next)
	{
		if (temp->type == REDIR)
		{
			if (ft_strchr(temp->str, '&') || ft_strchr(temp->str, '-'))
			{
				if (aggr_checks(temp, temp->next))
					return (true);
			}
			else
			{
				if (parse_redir_errors(temp->str, temp->next))
					return (true);
			}
			if (temp->next->type == REDIR && temp->next->next != NULL && \
				(ft_strchr(temp->str, '&') || ft_strchr(temp->str, '-')))
				temp = temp->next;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (false);
}
