/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:15:37 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 17:15:37 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

/*DELETE BEFORE SUBMIT*/
void	token_list_print(t_tok *token)
{
	t_tok	*temp;
	int i;
	i = 0;
	temp = token;
	NL;
	while (temp != NULL)
	{
		if (temp->str)
			ft_printf("token[%d] type [%d] = %s", i++, temp->type, temp->str);
		temp = temp->next;
		if (temp != NULL)
			NL;
	}
	if (temp == NULL)
		ft_printf("\ntoken[%d] (NULL)\n", i);
}

static bool	redir_validation(char *str, t_tok *next, int i)
{
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == '&')
		{
			if (next == NULL)
			{
				ft_perror("\nsyntax error near unexpected token `newline'\n");
				return (true);
			}
			return (false);
		}
		if (!ft_isdigit(str[i]))
		{
			ft_print_fd(2, "\n21sh parse error near `%c%c'\n", str[i], str[i + 1]);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool redir_error_checks(char *str, t_tok *next)
{
	if (ft_count_chrstr(str, '>') > 2)
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", ft_strchr(str, '>'));
		return (true);
	}
	if (ft_count_chrstr(str, '<') > 2)
	{
		ft_print_fd(2, "\n21sh parse error near `%s'\n", ft_strchr(str, '<'));
		return (true);
	}
	if (redir_validation(str, next, 0))
		return (true);
	return (false);
}

static bool	parse_error_check(t_tok *temp)
{
	while (temp)
	{
		if (temp->type == REDIR)
		{
			if (redir_error_checks(temp->str, temp->next))
				return (true);
			temp = temp->next;
		}
		temp = temp->next;
	}
	return (false);
}

t_tok	*parser(t_shell *shell)
{
	t_lex	list;

	ft_memset(&list, 0, sizeof(t_lex));
	shell->cmd_idx *= 2;
	if (shell->cmd_idx > 0)
		token_list_build(shell->cmd_line, shell->cmd_idx, &list);
	t_tok	*temp = list.token_list;
	token_list_print(temp);
	temp = list.token_list;
	if (parse_error_check(temp))
	{
		token_list_free(list.token_list);
		list.token_list = NULL;
	}
/* 	if (list.token_list)
	{
		temp = list.token_list;
	} */
	return (list.token_list);
}

// 2>&1 ---> redirect STDERR to STDOUT, redirects it to the same location
// 1>&2 ---> redirect STDOUT to STDERR, redirects it to the same location

// 0>&- = closes the STDIN
// 1>&- = closes the STDOUT
// 2>&- = closes the STDERR