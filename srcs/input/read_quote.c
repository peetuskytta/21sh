/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:49:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/02 15:25:58 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

// /*
// **	writes "dquote>" for open double quote and "quote>" for open single quote
// */
// static void	write_open_quote(char c)
// {
// 	if (c == S_QUOTE)
// 		ft_putstr_fd("quote>", STDOUT_FILENO);
// 	if (c == D_QUOTE)
// 		ft_putstr_fd("dquote>", STDOUT_FILENO);
// }

/*
**	Joins two strings together and returning a new pointer to the new joined
**	strings and frees s1 and s2.
*/
// static char	*strjoin_free(char *s1, char *s2)
// {
// 	char	*tmp;

// 	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
// 	ft_strcat(tmp, s1);
// 	ft_strcat(tmp, s2);
// 	ft_strdel(&s1);
// 	ft_strdel(&s2);
// 	return (tmp);
// }

/*
**	Reads new input to *extra and joines the new & extra. Checks if quotes
**	are closed or not and repeats the above if necessary.
*/
static void	read_until_quote(t_shell *shell)
{
	char	input[MAX_BUFF + 1];

	if (shell->cmd_idx >= MAX_BUFF)
		ft_realloc(shell->cmd_line, sizeof(char) * (MAX_BUFF + 1), sizeof(char) * (MAX_BUFF * 2 + 1));
	read_key(shell, input);
}

/*
**	Returns the character of the quote that is open.
*/
static void	identify_open_quote(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->cmd_line[i] != '\0')
	{
		if (shell->cmd_line[i] == CHAR_QUOTE || shell->cmd_line[i] == CHAR_DQUOTE)
			shell->quote = shell->cmd_line[i];
		while (shell->cmd_line[i] != '\0' && shell->cmd_line[i] != shell->quote)
		{
			if (shell->cmd_line[i] == shell->quote)
				shell->quote = -1;
			i++;
		}
		i++;
	}
}

/*
**	Quote handling "driver function" which identifies the open quote
**	and moves to read until new quote is found.
*/
void	read_quote(t_shell *shell)
{
	identify_open_quote(shell);
	if (shell->quote != -1)
		read_until_quote(shell);
}