/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:09:56 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/15 15:51:21 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** create the file on exit
*/
void	history_create(char **history)
{
	int	fd;
	int	i;

	fd = open(HIST_FILE, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRWXU);
	if (fd < 0)
	{
		ft_perror(HIST_ERR_FILE);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (history[i] != NULL)
		ft_putendl_fd(history[i++], fd);
}
