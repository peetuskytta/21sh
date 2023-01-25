/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_consume_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:05:15 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/25 16:43:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "ast.h"

/*
** Adds the token type WORD to the arguments array.
*/
static void	ast_add_arguments(t_tok ***token, t_ast *branch, int *i)
{
	if (*i < MAX_REDIR)
	{
		branch->data.args[(*i)] = ft_strdup((**token)->str);
		if (*i == 0)
			branch->data.cmd = ft_strdup(branch->data.args[0]);
		(*i)++;
		(**token) = (**token)->next;
	}
	else
		ft_perror("too many arguments...");
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
		ast_set_redir(&redir[(*idx)], (**token)->str);
		if ((**token)->next == NULL)
		{
			(**token) = (**token)->next;
			return ;
		}
		if ((**token)->next->type == REDIR)
		{
			(**token) = (**token)->next;
			redir[(*idx)].file = ft_strdup((**token)->str);
		}
		else
			redir[(*idx)].file = NULL;
		(*idx)++;
	}
	else
		ft_perror("too many redirections...");
	(**token) = (**token)->next;
}

	// Needs a way to detect the type of redirection and
	// separate the filename from the redirection
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
