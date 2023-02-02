/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:03:07 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 14:35:19 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

static int	identify_case(t_exec *data)
{
	if (ft_strequ(data->args[1], "-") == 1)
		return (CD_PREVIOUS);
	if (data->args[1] == NULL || ft_strequ(data->args[1], "--") == 1
		|| data->args[1][0] == '\0')
		return (CD_HOME);
	return (CD_NORMAL);
}

void	builtin_cd(t_shell *shell, t_exec data)
{
	int	checks;

	if (data.args[2] == NULL)
	{
		checks = identify_case(&data);
		if (checks == CD_NORMAL)
			checks = builtin_cd_change_dir(shell, &data);
		else if (checks == CD_HOME)
			builtin_cd_home(shell, &data, is_strenv("HOME", shell->environ));
		else if (checks == CD_PREVIOUS)
			builtin_cd_oldpwd(shell, &data,
				is_strenv("OLDPWD", shell->environ));
		if (checks == CD_ERR)
			return ;
	}
	else
		ft_perror(CD_ARG_NO);
}
