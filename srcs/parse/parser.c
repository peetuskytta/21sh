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

static bool	redir_amount(t_tok **first)
{
	t_tok	*temp;
	int		max;

	temp = *first;
	max = 0;
	while (temp)
	{
		if (temp->type == REDIR)
			max++;
		temp = temp->next;
	}
	if (max > MAX_REDIR)
	{
		ft_perror(MANY_ARG);
		return (false);
	}
	return (true);
}

static bool	word_amount(t_tok **first)
{
	t_tok	*temp;
	int		max;

	temp = *first;
	max = 0;
	while (temp)
	{
		if (temp->type == WORD)
			max++;
		temp = temp->next;
	}
	if (max > MAX_REDIR)
	{
		ft_perror(MANY_ARG);
		return (false);
	}
	return (true);
}

static void	check_for_heredoc(t_tok **first, t_shell *shell)
{
	t_tok	*temp;

	temp = *first;
	while (temp)
	{
		if (temp->type == REDIR && ft_strequ(temp->str, "<<") \
				&& temp->next != NULL)
		{
			if (enable_rawmode(shell) == 0)
				ft_perror(TCGET_ERR);
			if (tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw) == -1)
				ft_perror(TCGET_ERR);
			redir_heredoc(temp);
			if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &shell->orig_raw) == -1)
				ft_perror(TCGET_ERR);
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

/*DELETE BEFORE SUBMIT*/
void	token_list_print(t_tok *token)
{
	t_tok	*temp;
	int		i;

	i = 0;
	temp = token;
	ft_putchar('\n');
	while (temp != NULL)
	{
		if (temp->str)
			ft_printf("token[%d] type [%d] = %s", i++, temp->type, temp->str);
		temp = temp->next;
		if (temp != NULL)
			ft_putchar('\n');
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
	token_list_print(list.token_list);
	if (redir_amount(&list.token_list) == false
		|| word_amount(&list.token_list) == false)
	{
		token_list_free(list.token_list);
		return (NULL);
	}
	input_expand(shell, &list.token_list);
	input_strip_quotes(&list.token_list);
	parse_errors(&list.token_list);
	check_for_heredoc(&list.token_list, shell);
	return (list.token_list);
}
