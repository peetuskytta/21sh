/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:49:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/03 13:34:54 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/*
**	writes "dquote>" for open double quote and "quote>" for open single quote
*/
static void	write_open_quote(char c)
{
	if (c == S_QUOTE)
		ft_putstr_fd("quote>", STDOUT_FILENO);
	if (c == D_QUOTE)
		ft_putstr_fd("dquote>", STDOUT_FILENO);
}

/*
**	Joins two strings together and returning a new pointer to the new joined
**	strings and frees s1 and s2.
*/
static char	*strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcat(tmp, s1);
	ft_strcat(tmp, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (tmp);
}

/*
**	Reads new input to *extra and joines the new & extra. Checks if quotes
**	are closed or not and repeats the above if necessary.
*/
static char	*read_until_quote(char c, char *old, int bytes_read, int num_quotes)
{
	char	*new;
	char	*extra;

	new = ft_strdup(old);
	while (TRUE)
	{
		write_open_quote(c);
		extra = (char *)ft_memalloc(BUFFER + 1);
		bytes_read = read(0, extra, BUFFER);
		if (bytes_read < BUFFER + 1)
		{
			new = strjoin_free(new, extra);
			num_quotes = ft_count_chrstr(new, c);
			if (ft_is_oddnbr(num_quotes) == FALSE)
				break ;
		}
		else
			break ;
	}
	return (new);
}

/*
**	Returns the character of the quote that is open.
*/
static char	identify_open_quote(char *old, char c, int *quote)
{
	if (ft_is_oddnbr(quote[0]) && ft_is_oddnbr(quote[1]))
	{
		if (ft_strrchr(old, S_QUOTE))
			c = D_QUOTE;
		else
			c = S_QUOTE;
		return (c);
	}
	else if (ft_is_oddnbr(quote[0]))
		c = S_QUOTE;
	else if (ft_is_oddnbr(quote[1]))
		c = D_QUOTE;
	return (c);
}

/*
**	Quote handling "driver function" which identifies the open quote
**	and moves to read until new quote is found.
*/
char	*handle_open_quotes(t_shell *shell, char *buf, int *quotes)
{
	char	*new;
	char	c;

	c = EOF;
	c = identify_open_quote(buf, c, quotes);
	shell->quote = TRUE;
	new = read_until_quote(c, buf, 0, 0);
	return (new);
}
