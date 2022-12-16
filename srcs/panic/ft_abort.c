/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:59:10 by zraunio           #+#    #+#             */
/*   Updated: 2022/11/13 12:08:51 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** The abort() first unblocks the SIGABRT signal, and then raises that signal 
** for the calling process. This results in the abnormal termination of the 
** process unless the SIGABRT signal is caught and the signal handler does not
** return 
*/

void ft_abort(void)
{
	ft_perror(ft_strerror(ABORT_ERRNO));
	//sigabrt process handling here
	exit(EXIT_FAILURE);
}
