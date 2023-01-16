/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fetch_path_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:43:25 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/12 12:43:25 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

char	**exec_fetch_path_var(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			return (ft_strsplit(*env + 5, ':'));
		env++;
	}
	return (NULL);
}
