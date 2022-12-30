/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:59:10 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/30 16:26:56 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** The abort() first unblocks the SIGABRT signal, and then raises that signal 
** for the calling process. This results in the abnormal termination of the 
** process unless the SIGABRT signal is caught and the signal handler does not
** return 
** 	sigabrt process handling after PERROR!
*/

void	ft_abort(void)
{
	ft_perror(ft_strerror(ABORT_ERRNO));
	exit(EXIT_FAILURE);
}
