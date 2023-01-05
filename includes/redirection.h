/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:59:36 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/05 10:56:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "shell.h"
# include "structs.h"

typedef enum e_status
{
	GO,
	FILE_PERM,
	FOLDER_PERM,
	NO_FILE,
	FOLDER,
}		t_status;

void	redir_start(t_exec *data);
int		redir_file_check(char *str);
int		redir_folder_check(char *str);

#endif