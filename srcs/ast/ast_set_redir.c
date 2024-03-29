/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_set_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:24:54 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/01 19:24:54 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast.h"

static int	set_aggr_type(t_redir *redir, char *str)
{
	if (ft_strequ(">&", str))
		return (AGGR_COPY_BOTH);
	if (ft_strequ(">&-", str))
		return (AGGR_CLOSE_BOTH);
	if (ft_strequ("1>&-", str))
		return (AGGR_CLOSE_ONE);
	if (ft_strequ("2>&-", str))
		return (AGGR_CLOSE_TWO);
	if (ft_strequ("1>&2", str) || ft_strequ(">&", str))
		return (AGGR_COPY_ONE);
	if (ft_strequ("2>&1", str))
		return (AGGR_COPY_TWO);
	else
		return (redir->agre);
}

static int	check_for_type(t_redir *redir, char *str)
{
	int	type;

	type = -1;
	if (ft_strchr(str, '&'))
		redir->agre = set_aggr_type(redir, str);
	if ((str[0] == '<' && ft_strlen(str) == 1) || ft_strequ("<<", str))
		type = FILE_IN;
	if (ft_strchr(str, '>'))
	{
		if (ft_strnstr(str, ">>", 3))
			type = FILE_APPEND;
		else if (ft_strnstr(str, ">", 2))
			type = FILE_TRUNC;
		else
			type = FILE_PARSE_ERR;
		if (str[0] == '2')
			redir->fd_err = ERR_ON;
	}
	return (type);
}

void	ast_set_redir(t_redir *redir, char *str)
{
	redir->type = check_for_type(redir, str);
}
