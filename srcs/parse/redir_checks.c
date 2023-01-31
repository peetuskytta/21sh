/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:13:07 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 14:23:29 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

bool	redir_checks(t_tok *temp)
{
	while (temp->next)
	{
		if (temp->type == REDIR)
		{
/* 			if (ft_strchr(temp->str, '&') || ft_strchr(temp->str, '-'))
			{
				if (aggr_checks(temp, temp->next))
					return (true);
			} */
			if (!ft_strchr(temp->str, '&') || !ft_strchr(temp->str, '-'))
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
