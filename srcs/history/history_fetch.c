/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_fetch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:07:37 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/16 15:26:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** grab history from file
*/
void	history_fetch(t_shell *shell)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(HIST_FILE, O_RDONLY);
	if (fd > 0)
	{
		i = 0;
		while (get_next_line(fd, &line) > 0)
		{
			shell->history[i++] = ft_strdup(line);
			ft_strdel(&line);
		}
		shell->hist_idx = i - 1;
	}
	else
		ft_perror(HIST_ERR_FILE);
}
