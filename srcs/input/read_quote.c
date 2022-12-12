/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:49:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/12 11:04:56 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/*
**	Reads new input to *extra and joines the new & extra. Checks if quotes
**	are closed or not and repeats the above if necessary.
*/
// static void	read_until_quote(t_shell *shell)
// {
// 	char	input[MAX_BUFF + 1];

// 	if (shell->cmd_idx >= MAX_BUFF)
// 		ft_realloc(shell->cmd_line, sizeof(char) * (MAX_BUFF + 1), sizeof(char) * (MAX_BUFF * 2 + 1));
// 	read_key(shell, input);
// }

/*
**	Returns the character of the quote that is open.
*/
static void	identify_open_quote(t_shell *shell)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (shell->cmd_line[i] != '\0')
	{
		if ((shell->cmd_line[i] == D_QUOTE || shell->cmd_line[i] == S_QUOTE) && quote == 0)
		{
			shell->quote = shell->cmd_line[i];
			quote = 1;
		}
		else if (shell->cmd_line[i] == shell->quote && quote == 1)
		{
			shell->quote = EOF;
			quote = 0;
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
	if (ft_strchr(shell->cmd_line, D_QUOTE) || ft_strchr(shell->cmd_line, S_QUOTE))
		identify_open_quote(shell);
	// ft_putnbr_endl(shell->quote);
	// if (shell->quote != EOF)
	// 	read_until_quote(shell);
}
