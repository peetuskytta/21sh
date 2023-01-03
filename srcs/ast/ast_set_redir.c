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

#include "ast.h"

/*static bool	ft_charcmp(char one, char two)
{
	if (one == two)
		return (true);
	return (false);
}*/

static int	check_for_type(char *str)
{
	int	type;

	type = -1;
	if (ft_strchr(str, '>'))
	{
		if (ft_strstr(str, ">>"))
			type = FILE_APPEND;
		else
			type = FILE_TRUNC;
	}
	else if (ft_strchr(str, '<'))
		type = FILE_IN;
	return (type);
}

void	ast_set_redir(t_redir *redir, char *str)
{
	redir->type = check_for_type(str);
	if (ft_isdigit(str[0]))
		redir->fildes = ft_atoi(str);
	else
		redir->fildes = 1;
	if (redir->type == FILE_IN)
		redir->fildes = 0;
	if (ft_strchr(str, '&'))
		redir->aggr = FILE_AGGR;
	//ft_putnbr_endl(redir->fildes);
	//ft_putnbr_endl(redir->type);
}
