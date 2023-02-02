/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_fetch_cwd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:44:24 by pskytta           #+#    #+#             */
/*   Updated: 2023/02/02 14:41:30 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

void	builtin_cd_fetch_cwd(t_shell *shell)
{
	char	*cwd;

	ft_memdel((void *)&(shell->cwd));
	cwd = getcwd(NULL, 0);
	shell->cwd = ft_strdup(cwd);
	ft_memdel((void *)&(cwd));
}
