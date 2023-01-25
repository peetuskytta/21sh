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

static bool	type_error_case(char *str)
{
	if (ft_strstr(str, "<&>") || ft_strstr(str, ">&>"))
		return (true);
	if (ft_strstr(str, "<&<") || ft_strstr(str, ">&>"))
		return (true);
	if (ft_strstr(str, "<<>>") || ft_strstr(str, ">>>"))
		return (true);
	if (ft_strstr(str, "<<>>") || ft_strstr(str, "<<<"))
		return (true);
	if (ft_strstr(str, "><") || ft_strstr(str, "><>"))
		return (true);
	return (false);
}

static int	check_for_type(char *str)
{
	int	type;

	type = -1;
	if (type_error_case(str) == true)
		type = FILE_PARSE_ERR;
	else if (ft_strchr(str, '&'))
		type = FILE_AGGR;
	else if ((str[0] == '<' && ft_strlen(str) == 1) || ft_strequ("<<", str))
		type = FILE_IN;
	else if (ft_strchr(str, '>'))
	{
		if (ft_strnstr(str, ">>", 2))
			type = FILE_APPEND;
		else if (ft_strnstr(str, ">", 1))
			type = FILE_TRUNC;
		else
			type = FILE_PARSE_ERR;
	}
	return (type);
}

void	ast_set_redir(t_redir *redir, char *str)
{
	redir->type = check_for_type(str);
	if (ft_strequ("<<", str))
		redir->type = HEREDOC;
}
