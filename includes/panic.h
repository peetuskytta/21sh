/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:39:18 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/12 12:56:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PANIC_H
# define PANIC_H
# include "shell.h"
# include "structs.h"

/*
** PANIC
*/
void	ft_abort(void);
void	ft_perror(const char *s);
char	*ft_strerror(int errnum);

# endif
