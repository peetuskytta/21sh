/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:17:52 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/06 11:49:27 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	print_zplogo()
{
	ft_putendl_fd(" _____  __      _          _ _", STDIN_FILENO);
	ft_putendl_fd("/ __  \\/  |    | |        | | |", STDIN_FILENO);
	ft_putendl_fd("   / /  | | ___| |__   ___| | |", STDIN_FILENO);
	ft_putendl_fd("  / /   | |/ __|  _ \\ / _ \\ | |", STDIN_FILENO);
	ft_putendl_fd(" / /____| |\\__ \\ | | |  __/ | |", STDIN_FILENO);
	ft_putendl_fd("\\_____/\\___/___/_| |_|\\___|_|_|", STDIN_FILENO);
	ft_putendl_fd("\n		~zraunio & pskytta", STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
}

static void	print_pzlogo()
{
	ft_putendl_fd(" _____  __      _          _ _", STDIN_FILENO);
	ft_putendl_fd("/ __  \\/  |    | |        | | |", STDIN_FILENO);
	ft_putendl_fd("   / /  | | ___| |__   ___| | |", STDIN_FILENO);
	ft_putendl_fd("  / /   | |/ __|  _ \\ / _ \\ | |", STDIN_FILENO);
	ft_putendl_fd(" / /____| |\\__ \\ | | |  __/ | |", STDIN_FILENO);
	ft_putendl_fd("\\_____/\\___/___/_| |_|\\___|_|_|", STDIN_FILENO);
	ft_putendl_fd("\n		~pskytta & zraunio", STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
}

void	print_logo()
{
	int	i;

	ft_putstr_fd("\e[1;1H\e[2J", STDIN_FILENO);
	srand(time(NULL));
	i = (rand() % 2) + 1;
	if (i == 1)
		print_zplogo();
	else
		print_pzlogo();
}