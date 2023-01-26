/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_fetch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:07:37 by zraunio           #+#    #+#             */
/*   Updated: 2023/01/25 15:25:48 by pskytta          ###   ########.fr       */
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
	else if (fd < 0)
	{
		ft_perror("shell: ");
		ft_perror(HIST_ERR_FILE);
	}
	close(fd);
}
