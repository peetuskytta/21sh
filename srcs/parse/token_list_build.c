/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:15:32 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 23:21:21 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	init_token(t_tok *token, int size)
{
	token->str = (char *)ft_memalloc(sizeof(char) * size + 1);
	allocation_check((void *)(token->str));
	ft_memset(token->str, NULL_BYTE, size + 1);
	token->type = CHAR_NULL;
	token->next = NULL;
}

static char	get_char_type(char c)
{
	if (c == CHAR_DQUOTE)
		return (CHAR_DQUOTE);
	else if (c == CHAR_ESCAPE)
		return (CHAR_ESCAPE);
	else if (c == CHAR_GREATER)
		return (CHAR_GREATER);
	else if (c == CHAR_LESSER)
		return (CHAR_LESSER);
	else if (c == CHAR_PIPE)
		return (CHAR_PIPE);
	else if (c == CHAR_QUOTE)
		return (CHAR_QUOTE);
	else if (c == CHAR_SEMICOLON)
		return (CHAR_SEMICOLON);
	else if (c == CHAR_WHITESPACE)
		return (CHAR_WHITESPACE);
	else
		return (CHAR_GENERAL);
}

static void	change_state(t_tok *tok, int *state, int *k, char ch)
{
	tok->type = WORD;
	if (ch == CHAR_DQUOTE)
		*state = STATE_IN_DQUOTE;
	else if (ch == CHAR_QUOTE)
		*state = STATE_IN_QUOTE;
	else if (ch == CHAR_ESCAPE)
		*state = STATE_GENERAL;
	else if (ch == CHAR_GENERAL)
		*state = STATE_GENERAL;
	tok->str[*k] = ch;
	(*k)++;
}

void	token_list_build(char *input, int size, t_lex *list)
{
	t_tok	*token;
	char	ch_type;
	char	c;
	int		i;
	int		k;
	int		state;

	i = 0;
	k = 0;
	token = NULL;
	state = STATE_GENERAL;
	list->token_list = (t_tok *)ft_memalloc(sizeof(t_tok));
	token = list->token_list;
	init_token(token, size);
	c = input[i];
	while (c != NULL_BYTE)
	{
		c = input[i];
		ch_type = get_char_type(c);
		if (state == STATE_GENERAL)
		{
			if (ch_type == CHAR_QUOTE)
				change_state(token, &state, &k, CHAR_QUOTE);
			else if (ch_type == CHAR_DQUOTE)
				change_state(token, &state, &k, CHAR_DQUOTE);
			else if (ch_type == CHAR_ESCAPE)
				change_state(token, &state, &k, input[++i]);
			else if (ch_type == CHAR_GENERAL)
				change_state(token, &state, &k, c);
			else if (ch_type == CHAR_WHITESPACE)
			{
				if (k > 0)
				{
					token->str[k] = NULL_BYTE;
					token->next = (t_tok *)ft_memalloc(sizeof(t_tok));
					token = token->next;
					init_token(token, size - i);
					k = 0;
				}
			}
			else if (ch_type == CHAR_SEMICOLON || ch_type == CHAR_PIPE || ch_type == CHAR_GREATER || ch_type == CHAR_LESSER)
			{
				if (input[i] == CHAR_SEMICOLON && input[i + 1] == CHAR_SEMICOLON)
				{
					ft_print_fd(2, "21sh parse error near `%c%c'\n",input[i], input[i + 1]);
					token_list_free(list->token_list);
					list->token_list = NULL;
					return ;
				}
				if (k > 0)
				{
					token->str[k] = ch_type;
					token->next = (t_tok *)ft_memalloc(sizeof(t_tok));
					token = token->next;
					init_token(token, size - i);
					k = 0;
				}
				token->str[0] = ch_type;
				token->str[1] = NULL_BYTE;
				token->type = ch_type;
				token->next = (t_tok *)ft_memalloc(sizeof(t_tok));
				token = token->next;
				init_token(token, size - i);
			}
		}
		else if (state == STATE_IN_DQUOTE)
		{
			token->str[k++] = c;
			if (ch_type == CHAR_DQUOTE)
				state = STATE_GENERAL;
		}
		else if (state == STATE_IN_QUOTE)
		{
			token->str[k++] = c;
			if (ch_type == CHAR_QUOTE)
				state = STATE_GENERAL;
		}
		else if (ch_type == CHAR_NULL)
		{
			if (k > 0)
			{
				token->str[k] = NULL_BYTE;
				k = 0;
			}
		}
		//ft_printf("state: ch: c: {%d}---{%d}---{%c}\n", state, ch_type, c);
		i++;
	}
}