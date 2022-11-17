/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:02:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/17 15:52:50 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

static t_tok	*init_tokens(t_tok *token, char *input)
{
	size_t	size;

	size = ft_count_chrstr(input, CHAR_WHITESPACE);
	ft_printf("\naprox. number of tokens: %ld\n", size);
	token = (t_tok *)ft_memalloc(sizeof(t_tok) * size);
	allocation_check((void *)(token));
	ft_memset(token, 0, sizeof(t_tok) * size);
	return (token);

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
	else
		return (CHAR_GENERAL);
}

static void	change_state(t_tok *tok, int *state, int *k, char ch)
{
	tok->string[*k] = ch;
	(*k)++;
	if (ch == CHAR_DQUOTE)
		*state = STATE_IN_DQUOTE;
	else if (ch == CHAR_QUOTE)
		*state = STATE_IN_QUOTE;
	else if (ch == CHAR_ESCAPE)
		*state = STATE_IN_ESCAPE;
	else if (ch == CHAR_GENERAL)
		*state = STATE_GENERAL;
}

void	lexer(char *input)
{
	t_tok	*token;
	char	c;
	char	ch_type;
	int		i;
	int		k;
	int		tok;
	int		state;

	i = 0;
	k = 0;
	tok = 0;
	state = STATE_GENERAL;
	token = NULL;
	token = init_tokens(token, input);
	c = input[i];

	while (c != NULL_BYTE)
	{
		c = input[i];
		ch_type = get_char_type(c);
		if (state == STATE_GENERAL)
		{
			if (ch_type == CHAR_QUOTE)
				change_state(&token[tok], &state, &k, CHAR_QUOTE);
			else if (ch_type == CHAR_DQUOTE)
				change_state(&token[tok], &state, &k, CHAR_DQUOTE);
			else if (ch_type == CHAR_ESCAPE)
				change_state(&token[tok], &state, &k, input[i + 1]);
			else if (ch_type == CHAR_GENERAL)
				change_state(&token[tok], &state, &k, c);
			else if (ch_type == CHAR_WHITESPACE)
			{
				if (k > 0)
				{
					token[tok].string[--k] = NULL_BYTE;
					k = 0;
					tok++;
					token[tok].type = CHAR_NULL;
				}
			}
			if (ch_type == CHAR_SEMICOLON || ch_type == CHAR_PIPE)
			{
				if (k > 0)
				{
					token[tok].string[k] = NULL_BYTE;
					k = 0;
					tok++;
					token[tok].type = CHAR_NULL;
				}
				token[tok].type = (int)ch_type;
				token[tok].string[0] = ch_type;
				token[tok].string[1] = NULL_BYTE;
			}
		}
		else if (state == STATE_IN_DQUOTE)
		{
			token[tok].string[k++] = c;
			if (ch_type == CHAR_DQUOTE)
				state = STATE_GENERAL;
		}
		else if (state == STATE_IN_QUOTE)
		{
			token[tok].string[k++] = c;
			if (ch_type == CHAR_QUOTE)
				state = STATE_GENERAL;
		}
		else if (ch_type == CHAR_NULL)
		{
			if (k > 0)
			{
				token[tok].string[k] = NULL_BYTE;
				k = 0;
			}
		}
		//ft_printf("state: ch: c: {%d}---{%d}---{%c}\n", state, ch_type, c);
		i++;
	}
	i = 0;
	while (tok > i)
	{
		ft_printf("\ntype: {%d}\ntoken[%d]: {%s}\n", &token[i].type, i, &token[i].string);
		i++;
	}
}
