/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_consume_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:05:15 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/29 08:54:02 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Adds the token type WORD to the arguments array
*/
static void	ast_add_arguments(t_tok ***token, t_ast *branch, int *i)
{
	if (*i < MAX_REDIR)
	{
		branch->data.args[(*i)] = ft_strdup((**token)->str);
		//ft_putendl(branch->data.args[(*i)++]);
		(*i)++;
		(**token) = (**token)->next;
	}
	else
		ft_putendl_fd("too many arguments...", STDERR_FILENO);
}

/*
** Adds all redirections related to a command into an array of structs redir
** YET TO DO: set the type based on type, separate the name from the rest.
** fildes is set when the file is actually opened and then used as outfile.
*/
static void	ast_add_redir(t_tok ***token, t_redir *redir, int *idx)
{
	if (*idx < MAX_REDIR)
	{
		redir[(*idx)].file = ft_strdup((**token)->str);
		redir[(*idx)].type = FILE_OUT;
		redir[(*idx)].fildes = -1;
		(*idx)++;
		//ft_putendl(redir[(*idx)++].file);
	}
	else
		ft_putendl_fd("too many redirections...", STDERR_FILENO);
	(**token) = (**token)->next;

	// Needs a way to detect the type of redirection and
	// separate the filename from the redirection
}

/*
** Consumes the tokens to arguments and redirections
*/
void	ast_consume_tokens(t_tok ***token, t_ast *branch, int i)
{
	int	idx;

	idx = 0;
	while ((**token))
	{
		if ((**token)->type == WORD)
			ast_add_arguments(token, branch, &i);
		else if ((**token)->type == REDIR)
			ast_add_redir(token, branch->data.redir, &idx);
		else
			break ;
	}
}
