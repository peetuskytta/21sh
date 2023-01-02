/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:18:29 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/02 11:25:00 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	cmd_simple_execute(t_exec data, char **path)
{
	// builtin OR binary
	// if no binary found set ERRNO and STDERR "no command found"
	(void)data;
	(void)path;
}