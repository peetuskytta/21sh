/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:35:28 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/15 14:39:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void init_term(void)
{
	char	*term;
	char	term_buffer[MAX_BUFF];
	int		status;

	term = getenv("TERM");
	if (term  == NULL)
	{
		ft_print_fd(STDERR_FILENO, "could not get the TERM env\n");
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