/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_set_redir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:57:00 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/30 14:57:00 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static bool	ft_charcmp(char one, char two)
{
	if (one == two)
		return (true);
	return (false);
}

void	ast_set_redir(t_redir *redi, char *str)
{
	size_t	i;

	i = 0;
	if (ft_charcmp(str[i]))

	//redir.file = ft_strndup(str, i);

	redir.fildes = -1;
}
