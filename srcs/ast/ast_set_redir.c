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

/* static bool	type_error_case(char *str)
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
} */

static int	set_aggr_type(t_redir *redir, char *str)
{
	(void)redir;
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
		return (FILE_PARSE_ERR);
}

static int	check_for_type(t_redir *redir, char *str)
{
	int	type;

	type = -1;
	if (ft_strchr(str, '&'))
		type = set_aggr_type(redir, str);
	else if ((str[0] == '<' && ft_strlen(str) == 1) || ft_strequ("<<", str))
		type = FILE_IN;
	else if (ft_strchr(str, '>'))
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
/* 	if (ft_strequ("<<", str))
		redir->type = HEREDOC; */
	if (redir->type > 9)
		ft_putendl("\nFILE AGGR");
	if (redir->type == FILE_IN)
		ft_putendl("\nFILE_IN");
	if (redir->type == FILE_APPEND)
		ft_putendl("\nFILE_APPEND");
	if (redir->type == FILE_TRUNC)
		ft_putendl("\nFILE_TRUNC");
	if (redir->type == HEREDOC)
		ft_putendl("\nHEREDOC");
	if (redir->type == FILE_PARSE_ERR)
		ft_putendl("\nFILE_PARSE_ERR");
}
