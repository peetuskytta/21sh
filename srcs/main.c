/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:50:56 by pskytta           #+#    #+#             */
/*   Updated: 2022/10/31 15:30:16 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/shell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	ft_memset(&shell, EOF, sizeof(shell));
	if (argc && argv && envp)
		init_shell(&shell, envp);
	return (EXIT_SUCCESS);
}