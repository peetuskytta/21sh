/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:33:06 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/26 23:19:55 by pskytta          ###   ########.fr       */
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

static bool	redir_error_checks(char *str, t_tok *next)
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

static bool aggr_checks(char *str, t_tok *next)
{
	if (ft_strequ(">&", str) || ft_strequ(">&-", str)
		|| ft_strequ("1>&-", str) || ft_strequ("2>&-", str)
		|| ft_strequ("1>&2", str) || ft_strequ("2>&1", str))
		;
	else if (ft_strequ("0<&-", str))
	{
		ft_perror(BAD_FD);
		ft_perror("0<&-\n");
		return (true);
	}
	else
	{
		ft_perror(PARSE_ERR);
		ft_print_fd(STDERR_FILENO, "%s'\n", str);
		return (true);
	}
	//ft_print_fd(STDERR_FILENO, "%s\n", next->str);
	if (ft_strequ(">&", str) && (next->str == NULL || next->str[0] == '\0'
			|| ft_strequ(next->str, " ")))
	{
		ft_perror(SYNTAX_ERR);
		return (true);
	}
	return (false);
}

static bool	redir_check(t_tok *temp)
{
	while (temp->next)
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
			if (temp->next->type == REDIR && temp->next->next != NULL)
				temp = temp->next;
			temp = temp->next;
		}
		else
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
			if (temp->type == ';' && (temp->next->type == '|'
					|| temp->next->type == ';'))
			{
				ft_perror("\n21sh syntax error near unexpected token: ';'\n");
				return (true);
			}
			if (temp->type == '|' && (temp->next->type == '|'
					|| temp->next->type == ';'))
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
	if (*first == NULL)
		return ;
	else if (redir_check(temp) || separator_check(temp))
	{
		token_list_free(*first);
		*first = NULL;
	}
}
