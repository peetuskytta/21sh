/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:59:36 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/16 14:47:59 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "shell.h"
# include "structs.h"

typedef enum e_status
{
	FILE_ERR,
	FILE_PERM,
	FOLDER_PERM,
	NO_FILE,
	FOLDER,
}		t_status;

bool	redirection_loop(t_exec *data);
int		redir_file_check(t_redir *redir);
int		redir_folder_check(char *str);

#endif