/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:16:54 by zraunio           #+#    #+#             */
/*   Updated: 2022/10/06 16:59:43 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <stdint.h>
# include <sys/types.h>

int		ft_printf(const char *format, ...);
int		ft_print_fd(int fd, const char *format, ...);
int		ft_print_file(const char *file, const char *format, ...);
char	*format(const char *format, ...);

#endif
