/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:13:30 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/02 14:04:45 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static bool	pipe_check(t_tok **temp)
{
	if ((*temp)->type == CHAR_PIPE)
	{
		if ((*temp)->next->type == CHAR_PIPE || \
			(*temp)->next->type == CHAR_SEMICOLON || \
			(*temp)->next == NULL || (*temp)->next->str[0] == '\0')
		{
			ft_perror("21sh syntax error near unexpected token: '|'\n");
			return (true);
		}
	}
	return (false);
}

static bool	semicolon_check(t_tok ***temp)
{
	while ((**temp))
	{
		if ((**temp)->type == CHAR_SEMICOLON)
		{
			if ((**temp)->next->type == CHAR_SEMICOLON || \
				(**temp)->next->type == CHAR_PIPE || \
				(**temp)->next == NULL || (**temp)->next->str[0] == '\0')
			{
				ft_perror("21sh syntax error near unexpected token: ';'\n");
				return (true);
			}
		}
		if (pipe_check((*temp)))
			return (true);
		(**temp) = (**temp)->next;
	}
	return (false);
}

bool	separator_checks(t_tok **tok)
{
	if ((*tok)->type == ';')
	{
		ft_perror("21sh syntax error near unexpected token: ';'\n");
		return (true);
	}
	if ((*tok)->type == '|')
	{
		ft_perror("21sh syntax error near unexpected token: '|'\n");
		return (true);
	}
	if (semicolon_check(&tok))
		return (true);
	else
		return (false);
}
