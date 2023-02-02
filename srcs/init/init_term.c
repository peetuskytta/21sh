/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:35:28 by zraunio           #+#    #+#             */
/*   Updated: 2023/02/02 10:19:38 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_term(void)
{
	char	*term;
	char	term_buffer[MAX_BUFF];
	int		status;

	term = getenv("TERM");
	if (term == NULL)
	{
		ft_perror("could not get the TERM env\n");
		ft_perror(EMPTY_ENV);
		exit(EXIT_FAILURE);
	}
	status = tgetent(term_buffer, term);
	if (status < 0)
	{
		ft_print_fd(STDERR_FILENO, "could not access the termcap data base\n");
		exit(EXIT_FAILURE);
	}
	else if (status == 0)
	{
		ft_print_fd(STDERR_FILENO, "could not find the termtype\n");
		exit(EXIT_FAILURE);
	}
}
