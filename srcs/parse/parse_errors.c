/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:33:06 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 23:34:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	redir_validation(char *str, t_tok *next, int i)
{
	(void)i;
	(void)str;
	if (next == NULL)
	{
		ft_perror("syntax error near unexpected token `newline'\n");
		return (true);
	}
	else
	{
		if (ft_atoi(next->str))
		{
			ft_perror("not a valid file descriptor\n");
			return (true);
		}
	}
	return (false);
}

static bool	redir_error_checks(char *str, t_tok *next)
{
	if (ft_strequ(">", str) || ft_strequ(">>", str) || ft_strequ("<", str) \
		|| ft_strequ("<<", str) || ft_strequ("1>", str)
		|| ft_strequ("1>>", str) || ft_strequ("2>", str)
		|| ft_strequ("2>>", str) || ft_strequ("2>>1", str)
		|| ft_strequ("1>>2", str) || ft_strequ("1>2", str)
		|| ft_strequ("2>1", str))
		;
	else
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", str);
		return (true);
	}
	if (redir_validation(str, next, 0))
		return (true);
	return (false);
}

static bool aggr_checks(char *str, t_tok *next)
{
	if (next == NULL)
		return (true);
	if (ft_strequ(">&", str) || ft_strequ(">&-", str)
	|| ft_strequ("1>&-", str) || ft_strequ("2>&-", str)
	|| ft_strequ("1>&2", str) || ft_strequ("2>&1", str))
		;
	else
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", str);
		return (true);
	}
	return (false);
}

static bool	redir_check(t_tok *temp)
{
	while (temp)
	{
		if (temp->type == REDIR)
		{
			if (ft_strchr(temp->str, '&') || ft_strchr(temp->str, '-'))
			{
				if (aggr_checks(temp->str, temp->next))
					return (true);
			}
			else
			{
				if (redir_error_checks(temp->str, temp->next))
					return (true);
			}
			temp = temp->next;
		}
		temp = temp->next;
	}
	return (false);
}

static bool	separator_check(t_tok *temp)
{
	while (temp)
	{
		if (temp->type == ';' || temp->type == '|')
		{
			if (temp->type == ';' && (temp->next->type == '|' || temp->next->type == ';'))
			{
				ft_perror("\n21sh syntax error near unexpected token: ';'\n");
				return (true);
			}
			if (temp->type == '|' && (temp->next->type == '|' || temp->next->type == ';'))
			{
				ft_perror("\n21sh syntax error near unexpected token: '|'\n");
				return (true);
			}
		}
		temp = temp->next;
	}
	return (false);
}

void	parse_errors(t_tok **first)
{
	t_tok	*temp;

	temp = *first;
	if (redir_check(temp) || separator_check(temp))
	{
		token_list_free(*first);
		*first = NULL;
	}
}
