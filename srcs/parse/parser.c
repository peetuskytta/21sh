/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:26:02 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/31 13:26:02 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	check_for_heredoc(t_tok **first, t_shell *shell)
{
	t_tok	*temp;

	temp = *first;
	while (temp)
	{
		if (temp->type == REDIR && ft_strequ(temp->str, "<<"))
		{
			if (enable_rawmode(shell) == 0)
				ft_perror(TCGET_ERR);
			tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
			redir_heredoc(temp);
			tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
		}
		temp = temp->next;
	}
}

static int	whitespace_check(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0' && i != 0)
		return (0);
	return (1);
}

//DELETE BEFORE SUBMIT
void	token_list_print(t_tok **token)
{
	t_tok	*temp;
	int		i;

	i = 0;
	temp = *token;
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

t_tok	*parser(t_shell *shell)
{
	t_lex	list;
	int		lenght;

	ft_memset(&list, 0, sizeof(t_lex));
	lenght = ft_strilen(shell->q_input);
	if (whitespace_check(shell->q_input) != 0)
		token_list_build(shell->q_input, lenght, &list);
	else
		return (NULL);
	//if (&list.token_list)
	token_list_print(&list.token_list);
	input_expand(shell, &list.token_list);
	input_strip_quotes(&list.token_list);
	parse_errors(&list.token_list);
	check_for_heredoc(&list.token_list, shell);
	return (list.token_list);
}
