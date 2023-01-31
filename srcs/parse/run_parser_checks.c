/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:55:56 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 14:16:38 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

bool	run_parser_checks(t_tok *first)
{
	t_tok	*temp;

	temp = first;
	if (redir_checks(temp))
		return (true);
	// if (aggregation_check(temp))
	// 	return (true);
	if (separator_checks(&temp))
		return (true);
/* 	if (pipe_check(temp))
		return (true); */
	return (false);
}
