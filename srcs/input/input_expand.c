/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:45:33 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/06 13:10:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char	*build_argument(char *str, char *temp, int start)
{
	char	*res;

	if (start > 1)
		res = ft_strsub(str, 0, start - 1);
	else
		res = NULL;
	ft_memdel((void *)&(temp));
	return (res);
}

static void	expand_variable(t_shell *shell, t_tok *tok)
{
	char	*temp;
	int		len;
	int		w_len;
	int		index;

	len = ft_strchr_index(tok->str, '$', 'b') + 1;
	temp = ft_strsub(tok->str, len, ft_strlen(tok->str) - len);
	w_len = ft_strlen(temp) + 1;
	index = is_strenv(temp, shell->environ);
	temp = build_argument(tok->str, temp, len);
	ft_memdel((void *)&tok->str);
	if (index == -1)
		tok->str = ft_strdup("");
	else
	{
		len = ft_strlen(shell->environ[index]) - w_len;
		tok->str = ft_strsub(shell->environ[index], w_len, len);
	}
	if (temp != NULL)
		tok->str = ft_strjoin_free(temp, tok->str, 3);
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
		if (ft_strchr(temp->str, '$') && temp->str[1] != '\0')
			expand_token(shell, temp, 1);
		else if (temp->str[0] == '~' && (ft_isspace(temp->str[1])
				|| temp->str[1] == '\0' || temp->str[1] == '/'))
			expand_token(shell, temp, 2);
		temp = temp->next;
	}
}
