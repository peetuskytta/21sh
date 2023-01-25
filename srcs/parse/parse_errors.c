/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:33:06 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 18:16:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	redir_validation(char *str, t_tok *next, int i)
{
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			if (next == NULL)
			{
				ft_perror("\nsyntax error near unexpected token `newline'\n");
				return (true);
			}
			return (false);
		}
		if (!ft_isdigit(str[i]))
		{
			ft_perror(PARSE_ERR);
			ft_print_fd(STDERR_FILENO, "`%c%c'\n", str[i], str[i + 1]);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	redir_error_checks(char *str, t_tok *next)
{
	if (ft_strequ(">", str) || ft_strequ(">>", str) || ft_strequ("<", str) \
		|| ft_strequ("<<", str))
		;
	else if (ft_isalnum(str[0]))
		;
	else
	{
		ft_perror(PARSE_ERR);
		ft_print_fd(STDERR_FILENO, "%s'\n", str);
		return (true);
	}
	if (redir_validation(str, next, 0))
		return (true);
	return (false);
}

static bool	redir_check(t_tok *temp)
{
	while (temp)
	{
		if (temp->type == REDIR)
		{
			if (ft_strchr(temp->str, '&') || ft_strchr(temp->str, '-'))
				ft_perror("AGGR check here");
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
	if (redir_check(temp) || separator_check(temp))
	{
		token_list_free(*first);
		*first = NULL;
	}
}
