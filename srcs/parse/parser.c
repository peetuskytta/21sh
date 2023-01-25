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
	int		i;

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

static void	check_for_heredoc(t_tok **first, t_shell *shell)
{
	t_tok	*temp;

	temp = *first;
	while (temp)
	{
		if (temp->type == REDIR && ft_strequ(temp->str, "<<"))
		{
			if (enable_rawmode(shell) == 0)
				ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
			tcsetattr(STDIN_FILENO, TCSANOW, &shell->raw);
			redir_heredoc(shell, temp);
			tcsetattr(STDIN_FILENO, TCSANOW, &shell->orig_raw);
		}
		temp = temp->next;
	}
}

t_tok	*parser(t_shell *shell)
{
	t_lex	list;
	int		lenght;

	ft_memset(&list, 0, sizeof(t_lex));
	lenght = ft_strilen(shell->q_input);
	if (lenght > 0)
		token_list_build(shell->q_input, lenght, &list);
	/* They can add the function that starts stripping quotes and expands $ and ~
		here (all expandables are in the list.token_list).
		It needs to be done here, otherwise the redirections that have quotes would be parse errors in the function below.
		first expand
		then quote strip
	*/
	input_expand(shell, &list.token_list);
	parse_errors(&list.token_list);
	check_for_heredoc(&list.token_list, shell);
	return (list.token_list);
}
	// HEREDOC is not working with slash directories

	// read from our own input array to a file (save a ptr to the
	// beginning and end, then strsub ot copy to the file)

// 2>&1 ---> redirect STDERR to STDOUT, redirects it to the same location
// 1>&2 ---> redirect STDOUT to STDERR, redirects it to the same location

// 0>&- = closes the STDIN
// 1>&- = closes the STDOUT
// 2>&- = closes the STDERR
