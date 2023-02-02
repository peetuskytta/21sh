/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:45:33 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 11:34:57 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	expand_variable(t_shell *shell, t_tok *tok)
{
	char	*temp;
	int		len;
	int		w_len;
	int		index;

	temp = ft_strsub(tok->str, 1, ft_strlen(tok->str));
	w_len = ft_strlen(temp) + 1;
	index = is_strenv(temp, shell->environ);
	ft_memdel((void *)&tok->str);
	if (index == -1)
		tok->str = ft_strdup("");
	else
	{
		len = ft_strlen(shell->environ[index]) - w_len;
		tok->str = ft_strsub(shell->environ[index], w_len, len);
	}
	ft_memdel((void *)&(temp));
}

/*
**	Expands the tilde '~' to match what is stored in environment HOME
**	variable.
*/
static void	expand_home(t_shell *shell, t_tok *tok)
{
	char	temp[MAX_BUFF];
	char	value[MAX_BUFF * 2];
	int		index;

	index = is_strenv("HOME", shell->environ);
	if (index == -1)
	{
		ft_memdel((void *)&tok->str);
		tok->str = ft_strdup("");
	}
	else
	{
		ft_memset(temp, '\0', sizeof(char) * (MAX_BUFF));
		ft_memset(value, '\0', sizeof(char) * (MAX_BUFF * 2));
		if (tok->str[0] == '~' && tok->str[1] == '/')
			ft_strcpy(temp, tok->str + 1);
		ft_strcpy(value, shell->environ[index] + 5);
		ft_strcat(value, temp);
		ft_memdel((void *)&tok->str);
		tok->str = ft_strdup(value);
	}
}

static void	expand_token(t_shell *shell, t_tok *tok, int id)
{
	if (id == 1)
		expand_variable(shell, tok);
	if (id == 2)
		expand_home(shell, tok);
}

void	input_expand(t_shell *shell, t_tok **first)
{
	t_tok	*temp;

	temp = *first;

	while (temp != NULL)
	{
		if (is_builtin(temp->str) == false)
		{
			if (temp->str[0] == '$' && temp->str[1] != '\0')
				expand_token(shell, temp, 1);
			else if (temp->str[0] == '~' && temp->str[1] != '$'
				&& (ft_isspace(temp->str[1]) || temp->str[1] == '\0'
					|| temp->str[1] == '/'))
				expand_token(shell, temp, 2);
		}
		temp = temp->next;
	}
}
/*
** this will be list function instead. it needs the temp to point to head!!!!
** otherwise take the *str in the list and do the same thing
** while (next != NULL)
*/
