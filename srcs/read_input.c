/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:34:55 by pskytta           #+#    #+#             */
/*   Updated: 2022/11/03 10:13:21 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/*
**	Verification if quote is still unclosed.
*/
static int	odd_nbr_of_quotes(char *buf, int *quotes)
{
	quotes[0] = ft_count_chrstr(buf, S_QUOTE);
	quotes[1] = ft_count_chrstr(buf, D_QUOTE);
	if (ft_is_oddnbr(quotes[0]) || ft_is_oddnbr(quotes[1]))
		return (TRUE);
	return (FALSE);
}

/*
**	Checks for input's simplicity. If quotes are found it returns FALSE.
*/
static int	simple_input_check(char *input)
{
	if (ft_strchr(input, S_QUOTE))
		return (FALSE);
	if (ft_strchr(input, D_QUOTE))
		return (FALSE);
	else
		return (TRUE);
}

/*
**	Reads the stdin for input and moves to handle quotes if there is odd
**	number of either of the quotes.
*/
static char	*read_input_stdin(t_shell *shell, char *buf, int bytes_read)
{
	char	*new;
	int		quotes[2];

	ft_memset(buf, 0, BUFFER + 1);
	bytes_read = read(0, buf, BUFFER);
	if (bytes_read < BUFFER + 1 && simple_input_check(buf) == FALSE)
	{
		shell->quote = TRUE;
		if (odd_nbr_of_quotes(buf, quotes) == FALSE)
		{
			buf[bytes_read - 1] = '\0';
			return (buf);
		}
		new = handle_open_quotes(shell, buf, quotes);
		ft_memdel((void *)&(buf));
		return (new);
	}
	buf[bytes_read - 1] = '\0';
	return (buf);
}

/*
**	This loop only stops when "exit" is written to the STDIN.
*/
int	command_prompt_loop(t_shell *shell)
{
	t_lexer	lex;
	char	*buf;

	while (TRUE)
	{
		//write_prompt_and_folder(shell);
		write(1, "$> ", 4);
		buf = (char *)ft_memalloc(BUFFER + 1);
		buf = read_input_stdin(shell, buf, 0);
		shell->cmd_line = ft_strdup(buf);
		ft_strdel(&buf);
		ft_printf("\nbuf: %s\n\n", shell->cmd_line);
		lexer(shell->cmd_line, 1, &lex);
		exit(EXIT_SUCCESS);
	}
}