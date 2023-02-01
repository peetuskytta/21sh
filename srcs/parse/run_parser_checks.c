/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parser_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:18 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/01 11:11:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

bool	run_parser_checks(t_tok *first)
{
	t_tok	*temp;

	temp = first;
	if (redir_checks(temp))
		return (true);
	if (separator_checks(&temp))
		return (true);
	return (false);
}
