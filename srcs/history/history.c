/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:42:49 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/30 16:23:25 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* if empty, arrow up > NOTHING
** on enter, storing each command in order in an array
** on exit, those are stored in the history file
** on re-launch, file contents are copied back into the array
** to a limit of a 1000
** same process if you call ./21sh while running ./21sh
** older commands deleted once limit is reached 
*/

#include "../../includes/shell.h"

void	history(t_shell *shell)
{
	int	fd;

	fd = open(HIST_FILE, O_RDONLY);
	if (fd < 0)
		return ;
	(void)shell;
	close(fd);
}
