/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:59:36 by pskytta           #+#    #+#             */
/*   Updated: 2023/01/19 22:39:14 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "shell.h"
# include "structs.h"

# define HERE_DOC "/tmp/heredoc"

typedef enum e_status
{
	FILE_ERR = 11,
	FILE_PERM = 12,
	FOLDER_PERM = 13,
	NO_FILE = 14,
	FOLDER = 15,
	HEREDOC = 16,
}		t_status;

bool	redirection_loop(t_exec *data);
int		redir_file_check(t_redir *redir);
int		redir_folder_check(char *str);
void	redir_heredoc(t_exec *data);

#endif