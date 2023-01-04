/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:34:37 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/04 16:49:58 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shell.h"

static int verify_value(char *name)
{
	if (name == NULL || ft_strlen(name) == 0)
		return (0);
	else if (ft_strchr(name, '='))
		return (-1);
	else
		return (1);
}

static int	unset_errors(char *name, int index)
{
	if (verify_value(name) != 1)
	{
		ft_memdel((void *)&name);
		if (verify_value(name) == -1)
			ft_perror(INVALID_CHAR);
		else
			ft_perror(UNSETENV_USAGE);
		return (-1);
	}
	else if (index == -1)
	{
		ft_memdel((void *)&name);
		return (-1);
	}
	else
		return (1);
}

void	builtin_unsetenv(t_shell *shell, char *args)
{
	int		index;
	char	*name;

	index = 0;
	while (ft_isspace(args[index]) == 0 && args[index] != 0)
		index++;
	if (args[index] != '\0')
		name = ft_strsub(args, 0, index - 1);
	else
		name = ft_strdup(args);
	index = ft_is_strenv(name, shell->environ);
	if (unset_errors(name, index) == -1)
		return ;
	ft_arrtrim(shell->environ, index);
	shell->env_nbr--;
	ft_memdel((void *)&name);
}

// static void	variable_counter(t_shell *data, char **inherited_variables)
// {
// 	while (inherited_variables[data->env_nbr] != NULL)
// 		data->env_nbr++;
// }

// static void	allocate_envp(t_shell *data, char **env)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	variable_counter(data, env);
// 	count = data->env_nbr;
// 	data->environ = (char **)ft_memalloc(sizeof(char *) * (count + 1));
// 	while (env[i] != NULL)
// 	{
// 		data->environ[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	data->environ[data->env_nbr] = NULL;
// }

// int		main(int argc, char **argv, char **envp)
// {
// 	t_shell	shell;

// 	ft_memset(&shell, 0, sizeof(shell));
// 	allocate_envp(&shell, envp);
// 	if (argc)
// 		ft_unsetenv(&shell, argv[1]);
// 	return (0);
// }
