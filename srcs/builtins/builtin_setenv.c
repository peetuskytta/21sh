/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:53:38 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 14:36:24 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static void	setenv_error(int err)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	if (err == 0)
		ft_perror(NAME_ERROR);
	if (err == -1)
		ft_perror(SETENV_USAGE);
	if (err == -2)
		ft_perror(INVALID_CHAR);
}

static int	setenv_verify_value(char *name)
{
	if (name == NULL || ft_strlen(name) == 0)
		return (0);
	else if (ft_strchr(name, '=') == NULL)
		return (-1);
	else if (!ft_isalpha(name[0]))
		return (-2);
	else
		return (1);
}

static int	setenv_split(char *args, char **name, char **value)
{
	int	i;
	int	j;

	i = ft_strchr_index(args, '=', 'b');
	j = i;
	*name = ft_strsub(args, 0, i);
	if (*name == NULL)
		return (0);
	while (ft_isspace(args[i]) == 0 && args[i] != '\0')
		i++;
	*value = ft_strsub(args, j + 1, i - j);
	if (*value == NULL)
		return (-1);
	return (1);
}

void	builtin_setenv(t_shell *shell, t_exec data)
{
	char	*name;
	char	*value;
	int		valid;
	int		index;

	valid = setenv_verify_value(data.args[1]);
	if (valid != 1)
	{
		setenv_error(valid);
		return ;
	}
	else
	{
		valid = setenv_split(data.args[1], &name, &value);
		if (valid != 1)
		{
			setenv_error(valid);
			if (ft_strilen(name) && ft_strilen(value))
				ft_memdel_range(2, name, value);
			return ;
		}
		index = is_strenv(name, shell->environ);
		setenv_update_env(shell, name, value, index);
	}
}
