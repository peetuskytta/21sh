/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:45:33 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/24 15:39:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	expand_variable(t_shell *shell, t_exec *data, int i)
{
	char	*temp;
	int		len;
	int		w_len;
	int		index;

	temp = ft_strsub(data->args[i], 1, ft_strlen(data->args[i]));
	w_len = ft_strlen(temp) + 1;
	index = is_strenv(temp, shell->environ);
	ft_memdel((void *)&data->args[i]);
	if (index == -1)
		data->args[i] = ft_strdup("");
	else
	{
		len = ft_strlen(shell->environ[index]) - w_len;
		data->args[i] = ft_strsub(shell->environ[index], w_len, len);
	}
	ft_memdel((void *)&(temp));
}

/*
**	Expands the tilde '~' to match what is stored in environment HOME
**	variable.
*/
static void	expand_home(t_shell *shell, t_exec *data, int i)
{
	char	temp[MAX_BUFF];
	char	value[MAX_BUFF * 2];
	int		index;

	index = is_strenv("HOME", shell->environ);
	if (index == -1)
	{
		ft_memdel((void *)&data->args[i]);
		data->args[i] = ft_strdup("");
	}
	else
	{
		ft_memset(temp, '\0', sizeof(char) * (MAX_BUFF));
		ft_memset(value, '\0', sizeof(char) * (MAX_BUFF * 2));
		if (data->args[i][0] == '~' && data->args[i][1] == '/')
			ft_strcpy(temp, data->args[i] + 1);
		ft_strcpy(value, shell->environ[index] + 5);
		ft_strcat(value, temp);
		ft_memdel((void *)&data->args[i]);
		data->args[i] = ft_strdup(value);
	}
}

static void	expand_token(t_shell *shell, t_exec *data, int i, int id)
{
	if (id == 1)
		expand_variable(shell, data, i);
	if (id == 2)
		expand_home(shell, data, i);
}

void	input_expand(t_shell *shell, t_exec *data)
{
	int	i;

	i = 0;
	while (data->args[i] != NULL)
	{
		if (data->args[i][0] == '$' && data->args[i][1] != '\0')
			expand_token(shell, data, 1, i);
		else if (data->args[i][0] == '~' && data->args[i][1] != '$'
			&& (ft_isspace(data->args[i][1]) || data->args[i][1] == '\0'
			|| data->args[i][1] == '/'))
			expand_token(shell, data, 2, i);
		i++;
	}
}
/*
** this will be list function instead. it needs the temp to point to head!!!!
** otherwise take the *str in the list and do the same thing
** while (next != NULL)
** ft_perror(parse error)
** clean list with first item of list
** head = null (if clean doesn't handle it)
*/
