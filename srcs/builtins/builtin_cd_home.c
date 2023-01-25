/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:29 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/24 15:59:15 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buildin.h"

void	builtin_cd_home(t_shell *shell, int idx)
{
	(void)shell;
	if (idx == -1)
		ft_perror(CD_NO_HOME);
	else
	{
		//ft_putnbr_endl(idx);

	}

}
