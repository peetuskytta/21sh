/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:10:49 by pskytta           #+#    #+#             */
/*   Updated: 2022/07/21 22:10:49 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_directory(char *filename)
{
	struct stat	fileinfo;

	if (!filename)
		return (0);
	if (lstat(filename, &fileinfo) != 0)
		return (0);
	if (S_ISDIR(fileinfo.st_mode) == 1)
		return (1);
	return (0);
}
