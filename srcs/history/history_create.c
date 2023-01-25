/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:09:56 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 14:56:59 by zraunio          ###   ########.fr       */
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

	fd = open(HIST_FILE, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR \
		| S_IRWXU);
	if (fd < 0)
	{
		ft_perror(HIST_ERR_FILE);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (history[i] != NULL && i < 1000)
		ft_putendl_fd(history[i++], fd);
	if (close(fd) < 0)
		ft_perror(FILE_CLOSE_ERR);
}
