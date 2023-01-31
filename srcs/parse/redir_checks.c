/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:13:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 15:38:36 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	aggr_checks(t_tok *tok, t_tok *next)
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
		|| ft_strequ(next->str, " ")))
	{
		ft_perror(SYNTAX_ERR);
		return (true);
	}
	return (false);
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
			if (temp->next->type == REDIR && temp->next->next != NULL)
				temp = temp->next;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (false);
}
