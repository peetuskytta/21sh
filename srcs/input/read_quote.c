/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:49:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/08 14:50:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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


	i = 0;
	while (shell->cmd_line[i] != '\0')
	{
		if ((shell->cmd_line[i] == D_QUOTE || shell->cmd_line[i] == S_QUOTE) && shell->quote == EOF)
		{
			shell->quote = shell->cmd_line[i];
			shell->cmd_line = &shell->cmd_line [i + 1];
			i = ft_strchr_index(shell->cmd_line, shell->quote, 'b');
			if (i != ft_strilen(shell->cmd_line))
			{
				shell->quote = EOF;
			}
			else
				return ;
			// while (shell->cmd_line[i] != '\0' && shell->cmd_line[i] != shell->quote)
			// {
			// 	if (shell->cmd_line[i] == shell->quote)
			// 	{
			// 		shell->quote = EOF;
			// 		return ;
			// 	}
			// 	i++;
			// }
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
	// ft_putnbr_endl(shell->quote);
	// if (shell->quote != EOF)
	// 	read_until_quote(shell);
}
