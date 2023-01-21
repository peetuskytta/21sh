/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:53:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/21 14:59:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

static int setenv_verify_value(char *name)
{
	if (name == NULL || ft_strlen(name) == 0)
		return (0);
	else if (ft_strchr(name, '='))
		return (-1);
	else
		return (1);
}

static void	setenv_split(char *args, char **name, char **value)
{
	int	i;
	int	j;

	if (setenv_verify_value(args) == 0)
	{
		ft_printf("hello");
		ft_perror(SETENV_USAGE);
		return ;
	}
	else
	{
		i = ft_strchr_index(args, '=', 'b');
		j = i;
		*name = ft_strsub(args, 0,  i);
		if (*name == NULL)
			ft_abort();
		while (ft_isspace(args[i]) == 0 && args[i] != '\0')
			i++;
		*value = ft_strsub(args, j + 1, i - j);
		if (*value == NULL)
			ft_abort();
	}
}

void	builtin_setenv(t_shell *shell, t_exec data)
{
	char	*name;
	char	*value;
	int		valid;
	int		index;

	//if first character is not alpha error check
	setenv_split(data.args, &name, &value);
	valid = setenv_verify_value(name);
	if (valid != 1)
	{
		if (valid == 0)
			ft_perror(ft_strerror(ENV_NAME_ERRNO));
		else if (valid == -1)
			ft_perror(ft_strerror(ENV_INVALID_ERRNO));
		ft_memdel_range(2, name, value);
		return ;
	}
	else
	{
		index = ft_is_strenv(name, shell->environ);
		setenv_update_env(shell, name, value, index);
	}
}
